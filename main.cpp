#include <sys/types.h>
#include <unistd.h>
#include <print>

extern "C" {
#include <ps5/kernel.h>
}

#include "hv_defeat.h"
#include "util.h"

#define BUS_DATA_DEVICES_OFFSET  (0x1B80000 + 0x1D91478)
#define DEVICE_DEVLINK   0x18
#define DEVICE_NAMEUNIT  0x58
#define DEVICE_SOFTC     0x88
#define SOFTC_ZCN_BAR2_RES  0x18
#define RESOURCE_BUSHANDLE  0x10

int main()
{
    uint32_t fw = kernel_get_fw_version() & 0xFFFF0000;
    std::print("[+] FW: 0x{:x}\n", fw);

    const uint64_t data_offset = 0x1B80000;
    uint64_t kbase = (uint64_t)KERNEL_ADDRESS_DATA_BASE - data_offset;
    uint64_t bus_devs_addr = kbase + BUS_DATA_DEVICES_OFFSET;

    std::print("[+] Finding MP4 device...\n");
    uint64_t mp4_softc = 0;
    uint64_t device = kr8(bus_devs_addr);
    while (device != 0) {
        uint64_t nameunit_ptr = kr8(device + DEVICE_NAMEUNIT);
        if (nameunit_ptr != 0 && (nameunit_ptr >> 48) == 0xFFFF) {
            uint32_t name4 = kr4(nameunit_ptr);
            if (name4 == 0x3034706d) {
                mp4_softc = kr8(device + DEVICE_SOFTC);
                std::print("[+] Found mp40, softc=0x{:x}\n", mp4_softc);
                break;
            }
        }
        device = kr8(device + DEVICE_DEVLINK);
    }

    if (mp4_softc == 0) {
        std::print("[!] MP4 device not found\n");
        return -1;
    }

    uint64_t zcn_bar2 = kr8(kr8(mp4_softc + SOFTC_ZCN_BAR2_RES) + RESOURCE_BUSHANDLE);
    std::print("[+] zcn_bar2 = 0x{:x}\n", zcn_bar2);

    return run_hv_defeat(mp4_softc, zcn_bar2);
}
