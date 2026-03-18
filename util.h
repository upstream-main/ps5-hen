#pragma once
#include <cstdint>
#include <cstring>
#include <format>
#include <string>
#include <sys/cpuset.h>
#include <unistd.h>

struct sysent {
    uint32_t n_arg;
    uint32_t pad;
    uint64_t sy_call;
    uint64_t sy_auevent;
    uint64_t sy_systrace_args;
    uint32_t sy_entry;
    uint32_t sy_return;
    uint32_t sy_flags;
    uint32_t sy_thrcnt;
};

extern "C" {
#include <ps5/kernel.h>
int sceKernelGetCurrentCpu();
int sceKernelSendNotificationRequest(int, void *, size_t, int);
}

#include "offsets.h"

// global fw version - set once in stage0, used everywhere
inline uint32_t& g_fw() { static uint32_t v = 0; return v; }

// kernel r/w
static inline uint64_t kr8(uint64_t a) { uint64_t v; kernel_copyout(a, &v, 8); return v; }
static inline uint32_t kr4(uint64_t a) { uint32_t v; kernel_copyout(a, &v, 4); return v; }
static inline void kw8(uint64_t a, uint64_t v) { kernel_copyin(&v, a, 8); }
static inline void kw4(uint64_t a, uint32_t v) { kernel_copyin(&v, a, 4); }

// dmap r/w
static inline uint64_t dr4(uint64_t dmap, uint64_t pa) { return kr4(dmap + pa); }
static inline void     dw4(uint64_t dmap, uint64_t pa, uint32_t v) { kw4(dmap + pa, v); }

// tmr via ecam b0d18f2
#ifndef ECAM_B0D18F2
#define ECAM_B0D18F2 (0xF0000000ULL + 0x18ULL * 0x8000 + 2 * 0x1000)
#define TMR_INDEX_OFF 0x80
#define TMR_DATA_OFF  0x84
#endif
static inline uint32_t tmr_read(uint64_t dmap, uint32_t addr) {
    dw4(dmap, ECAM_B0D18F2 + TMR_INDEX_OFF, addr);
    return (uint32_t)dr4(dmap, ECAM_B0D18F2 + TMR_DATA_OFF);
}
static inline void tmr_write(uint64_t dmap, uint32_t addr, uint32_t val) {
    dw4(dmap, ECAM_B0D18F2 + TMR_INDEX_OFF, addr);
    dw4(dmap, ECAM_B0D18F2 + TMR_DATA_OFF, val);
}

// notification
static inline void notify(const std::string &msg) {
    struct { char pad[45]; char msg[3075]; } req{};
    std::memcpy(req.msg, msg.c_str(), std::min(msg.size(), sizeof(req.msg) - 1));
    sceKernelSendNotificationRequest(0, &req, sizeof(req), 0);
}


static inline int pin_to_core(int n) {
    uint64_t m[2] = {}; m[0] = (1 << n);
    return cpuset_setaffinity(3, 1, -1, 0x10, (const cpuset_t *)m);
}
static inline int pin_to_first_available_core() {
    for (int i = 0; i < 16; i++)
        if (pin_to_core(i) == 0) return i;
    return -1;
}
static inline void unpin() {
    uint64_t m[2] = {0xFFFF, 0};
    cpuset_setaffinity(3, 1, -1, 0x10, (const cpuset_t *)m);
}

// dmap
static inline uint64_t get_dmap_base() {
    static uint64_t c = 0;
    if (!c) {
        uint64_t kb = (uint64_t)KERNEL_ADDRESS_DATA_BASE - fw_off(g_fw(), "KDATA_OFFSET");
        int32_t i, d;
        kernel_copyout(kb + fw_off(g_fw(), "OFF_DMPML4I"), &i, 4);
        kernel_copyout(kb + fw_off(g_fw(), "OFF_DMPDPI"), &d, 4);
        c = ((uint64_t)d << 30) | ((uint64_t)i << 39) | 0xFFFF800000000000ULL;
    }
    return c;
}

static inline uint64_t get_dmap_addr(uint64_t pa) {
    return get_dmap_base() + pa;
}

// pmap_kextract
static inline uint64_t pmap_kextract(uint64_t va) {
    uint64_t kb = (uint64_t)KERNEL_ADDRESS_DATA_BASE - fw_off(g_fw(), "KDATA_OFFSET");
    int32_t dmpml4i, dmpdpi, pml4pml4i;
    kernel_copyout(kb + fw_off(g_fw(), "OFF_DMPML4I"), &dmpml4i, 4);
    kernel_copyout(kb + fw_off(g_fw(), "OFF_DMPDPI"), &dmpdpi, 4);
    kernel_copyout(kb + fw_off(g_fw(), "OFF_PML4PML4I"), &pml4pml4i, 4);

    uint64_t dm = ((uint64_t)dmpdpi << 30) | ((uint64_t)dmpml4i << 39) | 0xFFFF800000000000ULL;
    uint64_t de = ((uint64_t)(dmpml4i + 1) << 39) | 0xFFFF800000000000ULL;
    if (va >= dm && va < de) return va - dm;

    uint64_t pde_a = (((uint64_t)pml4pml4i << 39) | ((uint64_t)pml4pml4i << 30) |
                       0xFFFF800000000000ULL) + 8 * ((va >> 21) & 0x7FFFFFF);
    uint64_t pde; kernel_copyout(pde_a, &pde, 8);
    if (pde & 0x80) return (pde & 0xFFFFFFFE00000ULL) | (va & 0x1FFFFFULL);

    uint64_t pte_a = ((va >> 9) & 0xFE0) + dm + (pde & 0xFFFFFFFFFF000ULL);
    uint64_t pte; kernel_copyout(pte_a, &pte, 8);
    return (pte & 0xFFFFFFFFFF000ULL) | (va & 0x3FFFULL);
}

// page table bits
enum pde_shift {
    PDE_PRESENT = 0, PDE_RW, PDE_USER, PDE_WRITE_THROUGH,
    PDE_CACHE_DISABLE, PDE_ACCESSED, PDE_DIRTY, PDE_PS, PDE_GLOBAL,
    PDE_XOTEXT = 58, PDE_PROTECTION_KEY = 59, PDE_EXECUTE_DISABLE = 63
};
#define PDE_PRESENT_MASK         1UL
#define PDE_RW_MASK              1UL
#define PDE_PS_MASK              1UL
#define PDE_XOTEXT_MASK          1UL
#define PDE_PROTECTION_KEY_MASK  0xFUL
#define PDE_EXECUTE_DISABLE_MASK 1UL
#define PDE_ADDR_MASK            0xffffffffff800ULL
#define PDE_FIELD(pde, name)         (((pde) >> PDE_##name) & PDE_##name##_MASK)
#define PDE_ADDR(pde)                ((pde) & PDE_ADDR_MASK)
#define SET_PDE_BIT(pde, name)       ((pde) |= (PDE_##name##_MASK << PDE_##name))
#define CLEAR_PDE_BIT(pde, name)     ((pde) &= ~(PDE_##name##_MASK << PDE_##name))

// page table walk
static inline uint64_t find_pml4e(uint64_t pmap, uint64_t va, uint64_t *out) {
    uint64_t pm_pml4;
    kernel_copyout(pmap + fw_off(g_fw(), "PMAP_PM_PML4"), &pm_pml4, 8);
    if (!pm_pml4) return ~0ULL;
    uint64_t addr = pm_pml4 + (((va >> 39) & 0x1FF) * 8);
    kernel_copyout(addr, out, 8);
    return addr;
}
static inline uint64_t find_pdpe(uint64_t pmap, uint64_t va, uint64_t *out) {
    uint64_t pml4e;
    if (find_pml4e(pmap, va, &pml4e) == ~0ULL) return ~0ULL;
    uint64_t addr = get_dmap_addr(PDE_ADDR(pml4e)) + (((va >> 30) & 0x1FF) * 8);
    kernel_copyout(addr, out, 8);
    return addr;
}
static inline uint64_t find_pde(uint64_t pmap, uint64_t va, uint64_t *out) {
    uint64_t pdpe;
    if (find_pdpe(pmap, va, &pdpe) == ~0ULL) return ~0ULL;
    uint64_t addr = get_dmap_addr(PDE_ADDR(pdpe)) + (((va >> 21) & 0x1FF) * 8);
    kernel_copyout(addr, out, 8);
    return addr;
}
static inline uint64_t find_pte(uint64_t pmap, uint64_t va, uint64_t *out) {
    uint64_t pde;
    if (find_pde(pmap, va, &pde) == ~0ULL) return ~0ULL;
    uint64_t addr = get_dmap_addr(PDE_ADDR(pde)) + (((va >> 12) & 0x1FF) * 8);
    kernel_copyout(addr, out, 8);
    return addr;
}
