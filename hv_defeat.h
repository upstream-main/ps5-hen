#pragma once
#include <cstdint>
#include "offsets.h"

// ecam / pci config (hardware, not fw-dependent)
#define ECAM_BASE_PA        0xF0000000ULL
#define ECAM_B0D18F2        (ECAM_BASE_PA + 0x18ULL * 0x8000 + 2 * 0x1000)
#define TMR_INDEX_OFF       0x80
#define TMR_DATA_OFF        0x84

// tmr layout (hardware)
#define TMR_BASE(n)         ((n) * 0x10 + 0x00)
#define TMR_LIMIT(n)        ((n) * 0x10 + 0x04)
#define TMR_CONFIG(n)       ((n) * 0x10 + 0x08)
#define TMR_REQUESTORS(n)   ((n) * 0x10 + 0x0C)
#define TMR_CFG_PERMISSIVE  0x3F07
#define MAX_TMR             22
#define MAX_SAVED_TMRS      8

// vmcb offsets (amd svm spec, not fw-dependent)
#define VMCB_INTERCEPT_CR   0x00
#define VMCB_INTERCEPT_DR   0x04
#define VMCB_INTERCEPT_EXC  0x08
#define VMCB_INTERCEPT_MISC 0x0C
#define VMCB_INTERCEPT_VMXX 0x10
#define VMCB_TLB_CONTROL    0x58
#define VMCB_VMCB_CLEAN     0x5C
#define VMCB_NP_ENABLE      0x90

#define MAX_VMCBS           16

// context
struct hv_defeat_ctx {
    uint32_t fw;
    uint64_t kbase;
    uint64_t dmap_base;
    uint64_t hv_data_va;

    uint32_t saved_tmrs[MAX_SAVED_TMRS * 2];
    int saved_tmr_count;
    int tmr_disabled;

    uint64_t hv_data_pa;
    uint64_t vmcb_pas[MAX_VMCBS];
    int vmcb_count;
    int vmcbs_patched;

    uint64_t mp4_softc;
    uint64_t zcn_bar2;
};

int stage0_discover(hv_defeat_ctx *ctx);
int stage1_tmr_relax(hv_defeat_ctx *ctx);
int stage2_find_vmcbs(hv_defeat_ctx *ctx);
int stage3_patch_vmcbs(hv_defeat_ctx *ctx);
int stage3b_remove_xotext(hv_defeat_ctx *ctx);
int stage4_verify(hv_defeat_ctx *ctx);
int stage5_patch_kernel(hv_defeat_ctx *ctx);
int stage6_install_kexec(hv_defeat_ctx *ctx);
int stage7_run_hen(hv_defeat_ctx *ctx);
int kexec(uint64_t fptr);
int run_hv_defeat(uint64_t mp4_softc, uint64_t zcn_bar2);
