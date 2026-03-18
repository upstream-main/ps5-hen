#pragma once
#include <cstdint>
#include <string>
#include <unordered_map>
#include <format>

// All offsets relative to kbase (= KERNEL_ADDRESS_DATA_BASE - KDATA_OFFSET)

static const std::unordered_map<std::string, uint64_t> fw_offsets = {

    // FW 1.00
    {"0100_KDATA_OFFSET",     0x1B40000},
    {"0100_OFF_DMPML4I",      0x4ADF540},
    {"0100_OFF_DMPDPI",       0x4ADF544},
    {"0100_OFF_PML4PML4I",    0x4ADF29C},
    {"0100_OFF_PMAP_STORE",   0x4ADF2B8},
    {"0100_OFF_ALLPROC",      0x4411BF8},
    {"0100_KERNEL_TEXT_SIZE",  0x0B40000},
    {"0100_HV_VCPU",            0x1398},
    {"0100_HV_VCPU_CPUID",      0x128},
    {"0100_VMSPACE_VM_VMID",         0},  // TODO
    {"0100_VMSPACE_VM_PMAP",         0},  // TODO
    {"0100_PMAP_PM_PML4",         0x020},
    {"0100_DATA_BASE_GVMSPACE",      0},  // TODO
    {"0100_KERNEL_OFF_CODE_CAVE",    0x0044000},
    {"0100_PPR_SYSENT",        0x1CAA7B0},
    {"0100_GADGET_JMP_PTR_RSI",  0x0042000},

    // FW 1.01
    {"0101_KDATA_OFFSET",     0x1B40000},
    {"0101_OFF_DMPML4I",      0x4ADF540},
    {"0101_OFF_DMPDPI",       0x4ADF544},
    {"0101_OFF_PML4PML4I",    0x4ADF29C},
    {"0101_OFF_PMAP_STORE",   0x4ADF2B8},
    {"0101_OFF_ALLPROC",      0x4411BF8},
    {"0101_KERNEL_TEXT_SIZE",  0x0B40000},
    {"0101_HV_VCPU",            0x1398},
    {"0101_HV_VCPU_CPUID",      0x128},
    {"0101_VMSPACE_VM_VMID",         0},  // TODO
    {"0101_VMSPACE_VM_PMAP",         0},  // TODO
    {"0101_PMAP_PM_PML4",         0x020},
    {"0101_DATA_BASE_GVMSPACE",      0},  // TODO
    {"0101_KERNEL_OFF_CODE_CAVE",    0x0044000},
    {"0101_PPR_SYSENT",        0x1CAA7B0},
    {"0101_GADGET_JMP_PTR_RSI",  0x0042000},

    // FW 1.02
    {"0102_KDATA_OFFSET",     0x1B40000},
    {"0102_OFF_DMPML4I",      0x4ADF540},
    {"0102_OFF_DMPDPI",       0x4ADF544},
    {"0102_OFF_PML4PML4I",    0x4ADF29C},
    {"0102_OFF_PMAP_STORE",   0x4ADF2B8},
    {"0102_OFF_ALLPROC",      0x4411BF8},
    {"0102_KERNEL_TEXT_SIZE",  0x0B40000},
    {"0102_HV_VCPU",            0x1398},
    {"0102_HV_VCPU_CPUID",      0x128},
    {"0102_VMSPACE_VM_VMID",         0},  // TODO
    {"0102_VMSPACE_VM_PMAP",         0},  // TODO
    {"0102_PMAP_PM_PML4",         0x020},
    {"0102_DATA_BASE_GVMSPACE",      0},  // TODO
    {"0102_KERNEL_OFF_CODE_CAVE",    0x0044000},
    {"0102_PPR_SYSENT",        0x1CAA7B0},
    {"0102_GADGET_JMP_PTR_RSI",  0x0042000},

    // FW 1.05
    {"0105_KDATA_OFFSET",     0x1B40000},
    {"0105_OFF_DMPML4I",      0x4ADF5B0},
    {"0105_OFF_DMPDPI",       0x4ADF5B4},
    {"0105_OFF_PML4PML4I",    0x4ADF30C},
    {"0105_OFF_PMAP_STORE",   0x4ADF328},
    {"0105_OFF_ALLPROC",      0x4411C18},
    {"0105_KERNEL_TEXT_SIZE",  0x0B40000},
    {"0105_HV_VCPU",            0x1398},
    {"0105_HV_VCPU_CPUID",      0x128},
    {"0105_VMSPACE_VM_VMID",         0},  // TODO
    {"0105_VMSPACE_VM_PMAP",         0},  // TODO
    {"0105_PMAP_PM_PML4",         0x020},
    {"0105_DATA_BASE_GVMSPACE",      0},  // TODO
    {"0105_KERNEL_OFF_CODE_CAVE",    0x0044000},
    {"0105_PPR_SYSENT",        0x1CAA890},
    {"0105_GADGET_JMP_PTR_RSI",  0x0042000},

    // FW 1.10
    {"0110_KDATA_OFFSET",     0x1B40000},
    {"0110_OFF_DMPML4I",      0x4ADF5B0},
    {"0110_OFF_DMPDPI",       0x4ADF5B4},
    {"0110_OFF_PML4PML4I",    0x4ADF30C},
    {"0110_OFF_PMAP_STORE",   0x4ADF328},
    {"0110_OFF_ALLPROC",      0x4411C18},
    {"0110_KERNEL_TEXT_SIZE",  0x0B40000},
    {"0110_HV_VCPU",            0x1398},
    {"0110_HV_VCPU_CPUID",      0x128},
    {"0110_VMSPACE_VM_VMID",         0},  // TODO
    {"0110_VMSPACE_VM_PMAP",         0},  // TODO
    {"0110_PMAP_PM_PML4",         0x020},
    {"0110_DATA_BASE_GVMSPACE",      0},  // TODO
    {"0110_KERNEL_OFF_CODE_CAVE",    0x0044000},
    {"0110_PPR_SYSENT",        0x1CAA890},
    {"0110_GADGET_JMP_PTR_RSI",  0x0042000},

    // FW 1.11
    {"0111_KDATA_OFFSET",     0x1B40000},
    {"0111_OFF_DMPML4I",      0x4ADF5B0},
    {"0111_OFF_DMPDPI",       0x4ADF5B4},
    {"0111_OFF_PML4PML4I",    0x4ADF30C},
    {"0111_OFF_PMAP_STORE",   0x4ADF328},
    {"0111_OFF_ALLPROC",      0x4411C18},
    {"0111_KERNEL_TEXT_SIZE",  0x0B40000},
    {"0111_HV_VCPU",            0x1398},
    {"0111_HV_VCPU_CPUID",      0x128},
    {"0111_VMSPACE_VM_VMID",         0},  // TODO
    {"0111_VMSPACE_VM_PMAP",         0},  // TODO
    {"0111_PMAP_PM_PML4",         0x020},
    {"0111_DATA_BASE_GVMSPACE",      0},  // TODO
    {"0111_KERNEL_OFF_CODE_CAVE",    0x0044000},
    {"0111_PPR_SYSENT",        0x1CAA890},
    {"0111_GADGET_JMP_PTR_RSI",  0x0042000},

    // FW 1.12
    {"0112_KDATA_OFFSET",     0x1B40000},
    {"0112_OFF_DMPML4I",      0x4ADF5B0},
    {"0112_OFF_DMPDPI",       0x4ADF5B4},
    {"0112_OFF_PML4PML4I",    0x4ADF30C},
    {"0112_OFF_PMAP_STORE",   0x4ADF328},
    {"0112_OFF_ALLPROC",      0x4411C18},
    {"0112_KERNEL_TEXT_SIZE",  0x0B40000},
    {"0112_HV_VCPU",            0x1398},
    {"0112_HV_VCPU_CPUID",      0x128},
    {"0112_VMSPACE_VM_VMID",         0},  // TODO
    {"0112_VMSPACE_VM_PMAP",         0},  // TODO
    {"0112_PMAP_PM_PML4",         0x020},
    {"0112_DATA_BASE_GVMSPACE",      0},  // TODO
    {"0112_KERNEL_OFF_CODE_CAVE",    0x0044000},
    {"0112_PPR_SYSENT",        0x1CAA890},
    {"0112_GADGET_JMP_PTR_RSI",  0x0042000},

    // FW 1.13
    {"0113_KDATA_OFFSET",     0x1B40000},
    {"0113_OFF_DMPML4I",      0x4ADF5B0},
    {"0113_OFF_DMPDPI",       0x4ADF5B4},
    {"0113_OFF_PML4PML4I",    0x4ADF30C},
    {"0113_OFF_PMAP_STORE",   0x4ADF328},
    {"0113_OFF_ALLPROC",      0x4411C18},
    {"0113_KERNEL_TEXT_SIZE",  0x0B40000},
    {"0113_HV_VCPU",            0x1398},
    {"0113_HV_VCPU_CPUID",      0x128},
    {"0113_VMSPACE_VM_VMID",         0},  // TODO
    {"0113_VMSPACE_VM_PMAP",         0},  // TODO
    {"0113_PMAP_PM_PML4",         0x020},
    {"0113_DATA_BASE_GVMSPACE",      0},  // TODO
    {"0113_KERNEL_OFF_CODE_CAVE",    0x0044000},
    {"0113_PPR_SYSENT",        0x1CAA890},
    {"0113_GADGET_JMP_PTR_RSI",  0x0042000},

    // FW 1.14
    {"0114_KDATA_OFFSET",     0x1B40000},
    {"0114_OFF_DMPML4I",      0x4ADF5B0},
    {"0114_OFF_DMPDPI",       0x4ADF5B4},
    {"0114_OFF_PML4PML4I",    0x4ADF30C},
    {"0114_OFF_PMAP_STORE",   0x4ADF328},
    {"0114_OFF_ALLPROC",      0x4411C18},
    {"0114_KERNEL_TEXT_SIZE",  0x0B40000},
    {"0114_HV_VCPU",            0x1398},
    {"0114_HV_VCPU_CPUID",      0x128},
    {"0114_VMSPACE_VM_VMID",         0},  // TODO
    {"0114_VMSPACE_VM_PMAP",         0},  // TODO
    {"0114_PMAP_PM_PML4",         0x020},
    {"0114_DATA_BASE_GVMSPACE",      0},  // TODO
    {"0114_KERNEL_OFF_CODE_CAVE",    0x0044000},
    {"0114_PPR_SYSENT",        0x1CAA890},
    {"0114_GADGET_JMP_PTR_RSI",  0x0042000},

    // FW 2.00
    {"0200_KDATA_OFFSET",      0x1B80000},
    {"0200_OFF_DMPML4I",      0x4CB3B50},
    {"0200_OFF_DMPDPI",       0x4CB3B54},
    {"0200_OFF_PML4PML4I",    0x4CB38AC},
    {"0200_OFF_PMAP_STORE",   0x4CB38C8},
    {"0200_OFF_ALLPROC",      0x44B1C28},
    {"0200_KERNEL_TEXT_SIZE",  0x0B70000},
    {"0200_HV_VCPU",   0x1398},
    {"0200_HV_VCPU_CPUID",      0x128},
    {"0200_VMSPACE_VM_VMID",      0x1E4},
    {"0200_VMSPACE_VM_PMAP",      0x1D0},
    {"0200_PMAP_PM_PML4",         0x020},
    {"0200_DATA_BASE_GVMSPACE", 0x063A2EB0},
    {"0200_KERNEL_OFF_CODE_CAVE",    0x0044000},
    {"0200_PPR_SYSENT",              0x1CE6D10},
    {"0200_GADGET_JMP_PTR_RSI",      0x0042000},

    // FW 2.20
    {"0220_KDATA_OFFSET",      0x1B80000},
    {"0220_OFF_DMPML4I",      0x4CB3B50},
    {"0220_OFF_DMPDPI",       0x4CB3B54},
    {"0220_OFF_PML4PML4I",    0x4CB38AC},
    {"0220_OFF_PMAP_STORE",   0x4CB38C8},
    {"0220_OFF_ALLPROC",      0x44B1C28},
    {"0220_KERNEL_TEXT_SIZE",  0x0B70000},
    {"0220_HV_VCPU",            0x1398},
    {"0220_HV_VCPU_CPUID",      0x128},
    {"0220_VMSPACE_VM_VMID",     0x1E4},
    {"0220_VMSPACE_VM_PMAP",     0x1D0},
    {"0220_PMAP_PM_PML4",        0x020},
    {"0220_DATA_BASE_GVMSPACE", 0x063A2EB0},
    {"0220_KERNEL_OFF_CODE_CAVE",    0x0044000},
    {"0220_PPR_SYSENT",        0x1CE6DD0},
    {"0220_GADGET_JMP_PTR_RSI",  0x0042000},

    // FW 2.25
    {"0225_KDATA_OFFSET",      0x1B80000},
    {"0225_OFF_DMPML4I",      0x4CB3B50},
    {"0225_OFF_DMPDPI",       0x4CB3B54},
    {"0225_OFF_PML4PML4I",    0x4CB38AC},
    {"0225_OFF_PMAP_STORE",   0x4CB38C8},
    {"0225_OFF_ALLPROC",      0x44B1C28},
    {"0225_KERNEL_TEXT_SIZE",  0x0B70000},
    {"0225_HV_VCPU",            0x1398},
    {"0225_HV_VCPU_CPUID",      0x128},
    {"0225_VMSPACE_VM_VMID",     0x1E4},
    {"0225_VMSPACE_VM_PMAP",     0x1D0},
    {"0225_PMAP_PM_PML4",        0x020},
    {"0225_DATA_BASE_GVMSPACE", 0x063A2EB0},
    {"0225_KERNEL_OFF_CODE_CAVE",    0x0044000},
    {"0225_PPR_SYSENT",        0x1CE6DD0},
    {"0225_GADGET_JMP_PTR_RSI",  0x0042000},

    // FW 2.26
    {"0226_KDATA_OFFSET",      0x1B80000},
    {"0226_OFF_DMPML4I",      0x4CB3B50},
    {"0226_OFF_DMPDPI",       0x4CB3B54},
    {"0226_OFF_PML4PML4I",    0x4CB38AC},
    {"0226_OFF_PMAP_STORE",   0x4CB38C8},
    {"0226_OFF_ALLPROC",      0x44B1C28},
    {"0226_KERNEL_TEXT_SIZE",  0x0B70000},
    {"0226_HV_VCPU",            0x1398},
    {"0226_HV_VCPU_CPUID",      0x128},
    {"0226_VMSPACE_VM_VMID",     0x1E4},
    {"0226_VMSPACE_VM_PMAP",     0x1D0},
    {"0226_PMAP_PM_PML4",        0x020},
    {"0226_DATA_BASE_GVMSPACE", 0x063A2EB0},
    {"0226_KERNEL_OFF_CODE_CAVE",    0x0044000},
    {"0226_PPR_SYSENT",        0x1CE6DD0},
    {"0226_GADGET_JMP_PTR_RSI",  0x0042000},

    // FW 2.30
    {"0230_KDATA_OFFSET",      0x1B80000},
    {"0230_OFF_DMPML4I",      0x4CB3B50},
    {"0230_OFF_DMPDPI",       0x4CB3B54},
    {"0230_OFF_PML4PML4I",    0x4CB38AC},
    {"0230_OFF_PMAP_STORE",   0x4CB38C8},
    {"0230_OFF_ALLPROC",      0x44B1C28},
    {"0230_KERNEL_TEXT_SIZE",  0x0B70000},
    {"0230_HV_VCPU",            0x1398},
    {"0230_HV_VCPU_CPUID",      0x128},
    {"0230_VMSPACE_VM_VMID",     0x1E4},
    {"0230_VMSPACE_VM_PMAP",     0x1D0},
    {"0230_PMAP_PM_PML4",        0x020},
    {"0230_DATA_BASE_GVMSPACE", 0x063A2EB0},
    {"0230_KERNEL_OFF_CODE_CAVE",    0x0044000},
    {"0230_PPR_SYSENT",        0x1CE6DE0},
    {"0230_GADGET_JMP_PTR_RSI",  0x0042000},

    // FW 2.50
    {"0250_KDATA_OFFSET",      0x1B80000},
    {"0250_OFF_DMPML4I",      0x4CB3B50},
    {"0250_OFF_DMPDPI",       0x4CB3B54},
    {"0250_OFF_PML4PML4I",    0x4CB38AC},
    {"0250_OFF_PMAP_STORE",   0x4CB38C8},
    {"0250_OFF_ALLPROC",      0x44B1C28},
    {"0250_KERNEL_TEXT_SIZE",  0x0B70000},
    {"0250_HV_VCPU",            0x1398},
    {"0250_HV_VCPU_CPUID",      0x128},
    {"0250_VMSPACE_VM_VMID",     0x1E4},
    {"0250_VMSPACE_VM_PMAP",     0x1D0},
    {"0250_PMAP_PM_PML4",        0x020},
    {"0250_DATA_BASE_GVMSPACE", 0x063A2EB0},
    {"0250_KERNEL_OFF_CODE_CAVE",    0x0044000},
    {"0250_PPR_SYSENT",        0x1CE6E00},
    {"0250_GADGET_JMP_PTR_RSI",  0x0042000},

    // FW 2.70
    {"0270_KDATA_OFFSET",      0x1B80000},
    {"0270_OFF_DMPML4I",      0x4CB3B50},
    {"0270_OFF_DMPDPI",       0x4CB3B54},
    {"0270_OFF_PML4PML4I",    0x4CB38AC},
    {"0270_OFF_PMAP_STORE",   0x4CB38C8},
    {"0270_OFF_ALLPROC",      0x44B1C28},
    {"0270_KERNEL_TEXT_SIZE",  0x0B70000},
    {"0270_HV_VCPU",            0x1398},
    {"0270_HV_VCPU_CPUID",      0x128},
    {"0270_VMSPACE_VM_VMID",     0x1E4},
    {"0270_VMSPACE_VM_PMAP",     0x1D0},
    {"0270_PMAP_PM_PML4",        0x020},
    {"0270_DATA_BASE_GVMSPACE", 0x063A2EB0},
    {"0270_KERNEL_OFF_CODE_CAVE",    0x0044000},
    {"0270_PPR_SYSENT",              0},  // TODO
    {"0270_GADGET_JMP_PTR_RSI",  0x0042000},

    // FW 3.00
    {"0300_KDATA_OFFSET",     0x0BD0000},
    {"0300_OFF_DMPML4I",            0},  // TODO: need 3.xx kernel dump
    {"0300_OFF_DMPDPI",             0},  // TODO
    {"0300_OFF_PML4PML4I",          0},  // TODO
    {"0300_OFF_PMAP_STORE",         0},  // TODO
    {"0300_OFF_ALLPROC",      0x333DC58},
    {"0300_KERNEL_TEXT_SIZE",  0x0BD0000},
    {"0300_HV_VCPU",            0x1398},
    {"0300_HV_VCPU_CPUID",      0x128},
    {"0300_VMSPACE_VM_VMID",         0},  // TODO
    {"0300_VMSPACE_VM_PMAP",         0},  // TODO
    {"0300_PMAP_PM_PML4",            0},  // TODO
    {"0300_DATA_BASE_GVMSPACE",      0},  // TODO
    {"0300_KERNEL_OFF_CODE_CAVE",    0x0044000},
    {"0300_GADGET_JMP_PTR_RSI",  0x0042000},

    // FW 3.10
    {"0310_KDATA_OFFSET",     0x0BD0000},
    {"0310_OFF_DMPML4I",            0},  // TODO
    {"0310_OFF_DMPDPI",             0},  // TODO
    {"0310_OFF_PML4PML4I",          0},  // TODO
    {"0310_OFF_PMAP_STORE",         0},  // TODO
    {"0310_OFF_ALLPROC",      0x333DC58},
    {"0310_KERNEL_TEXT_SIZE",  0x0BD0000},
    {"0310_HV_VCPU",            0x1398},
    {"0310_HV_VCPU_CPUID",      0x128},
    {"0310_VMSPACE_VM_VMID",         0},  // TODO
    {"0310_VMSPACE_VM_PMAP",         0},  // TODO
    {"0310_PMAP_PM_PML4",            0},  // TODO
    {"0310_DATA_BASE_GVMSPACE",      0},  // TODO
    {"0310_KERNEL_OFF_CODE_CAVE",    0x0044000},
    {"0310_GADGET_JMP_PTR_RSI",  0x0042000},

    // FW 3.20
    {"0320_KDATA_OFFSET",     0x0BD0000},
    {"0320_OFF_DMPML4I",            0},  // TODO
    {"0320_OFF_DMPDPI",             0},  // TODO
    {"0320_OFF_PML4PML4I",          0},  // TODO
    {"0320_OFF_PMAP_STORE",         0},  // TODO
    {"0320_OFF_ALLPROC",      0x333DC58},
    {"0320_KERNEL_TEXT_SIZE",  0x0BD0000},
    {"0320_HV_VCPU",            0x1398},
    {"0320_HV_VCPU_CPUID",      0x128},
    {"0320_VMSPACE_VM_VMID",         0},  // TODO
    {"0320_VMSPACE_VM_PMAP",         0},  // TODO
    {"0320_PMAP_PM_PML4",            0},  // TODO
    {"0320_DATA_BASE_GVMSPACE",      0},  // TODO
    {"0320_KERNEL_OFF_CODE_CAVE",    0x0044000},
    {"0320_GADGET_JMP_PTR_RSI",  0x0042000},

    // FW 3.21
    {"0321_KDATA_OFFSET",     0x0BD0000},
    {"0321_OFF_DMPML4I",            0},  // TODO
    {"0321_OFF_DMPDPI",             0},  // TODO
    {"0321_OFF_PML4PML4I",          0},  // TODO
    {"0321_OFF_PMAP_STORE",         0},  // TODO
    {"0321_OFF_ALLPROC",      0x333DC58},
    {"0321_KERNEL_TEXT_SIZE",  0x0BD0000},
    {"0321_HV_VCPU",            0x1398},
    {"0321_HV_VCPU_CPUID",      0x128},
    {"0321_VMSPACE_VM_VMID",         0},  // TODO
    {"0321_VMSPACE_VM_PMAP",         0},  // TODO
    {"0321_PMAP_PM_PML4",            0},  // TODO
    {"0321_DATA_BASE_GVMSPACE",      0},  // TODO
    {"0321_KERNEL_OFF_CODE_CAVE",    0x0044000},
    {"0321_GADGET_JMP_PTR_RSI",  0x0042000},

    // FW 4.00
    {"0400_KDATA_OFFSET",       0x0C00000},
    {"0400_OFF_DMPML4I",       0x3E57D00},
    {"0400_OFF_DMPDPI",        0x3E57D04},
    {"0400_OFF_PML4PML4I",     0x3E57A5C},
    {"0400_OFF_PMAP_STORE",    0x3E57A78},
    {"0400_OFF_ALLPROC",       0x33EDCB8},
    {"0400_KERNEL_TEXT_SIZE",  0x0C00000},
    {"0400_HV_VCPU",            0x1398},
    {"0400_HV_VCPU_CPUID",      0x128},
    {"0400_VMSPACE_VM_VMID",         0},  // TODO
    {"0400_VMSPACE_VM_PMAP",         0},  // TODO
    {"0400_PMAP_PM_PML4",         0x028},
    {"0400_DATA_BASE_GVMSPACE", 0x064C3F80},
    {"0400_KERNEL_OFF_CODE_CAVE",    0x0044000},
    {"0400_PPR_SYSENT",        0x0D709C0},
    {"0400_GADGET_JMP_PTR_RSI",  0x0042000},

    // FW 4.02
    {"0402_KDATA_OFFSET",       0x0C00000},
    {"0402_OFF_DMPML4I",       0x3E57D00},
    {"0402_OFF_DMPDPI",        0x3E57D04},
    {"0402_OFF_PML4PML4I",     0x3E57A5C},
    {"0402_OFF_PMAP_STORE",    0x3E57A78},
    {"0402_OFF_ALLPROC",       0x33EDCB8},
    {"0402_KERNEL_TEXT_SIZE",  0x0C00000},
    {"0402_HV_VCPU",            0x1398},
    {"0402_HV_VCPU_CPUID",      0x128},
    {"0402_VMSPACE_VM_VMID",         0},  // TODO
    {"0402_VMSPACE_VM_PMAP",         0},  // TODO
    {"0402_PMAP_PM_PML4",         0x028},
    {"0402_DATA_BASE_GVMSPACE", 0x064C3F80},
    {"0402_KERNEL_OFF_CODE_CAVE",    0x0044000},
    {"0402_PPR_SYSENT",        0x0D709C0},
    {"0402_GADGET_JMP_PTR_RSI",  0x0042000},

    // FW 4.03
    {"0403_KDATA_OFFSET",       0x0C00000},
    {"0403_OFF_DMPML4I",       0x3E57D00},
    {"0403_OFF_DMPDPI",        0x3E57D04},
    {"0403_OFF_PML4PML4I",     0x3E57A5C},
    {"0403_OFF_PMAP_STORE",    0x3E57A78},
    {"0403_OFF_ALLPROC",       0x33EDCB8},
    {"0403_KERNEL_TEXT_SIZE",  0x0C00000},
    {"0403_KERNEL_OFF_CODE_CAVE",    0x0044000},
    {"0403_PPR_SYSENT",        0x0D709C0},
    {"0403_GADGET_JMP_PTR_RSI",  0x0042000},
    {"0403_HV_VCPU",            0x1398},
    {"0403_HV_VCPU_CPUID",      0x128},
    {"0403_VMSPACE_VM_VMID",         0},  // TODO
    {"0403_VMSPACE_VM_PMAP",         0},  // TODO
    {"0403_PMAP_PM_PML4",         0x028},
    {"0403_DATA_BASE_GVMSPACE", 0x064C3F80},

    // FW 4.50
    {"0450_KDATA_OFFSET",       0x0C00000},
    {"0450_OFF_DMPML4I",       0x3E57D00},
    {"0450_OFF_DMPDPI",        0x3E57D04},
    {"0450_OFF_PML4PML4I",     0x3E57A5C},
    {"0450_OFF_PMAP_STORE",    0x3E57A78},
    {"0450_OFF_ALLPROC",       0x33EDCB8},
    {"0450_KERNEL_TEXT_SIZE",  0x0C00000},
    {"0450_HV_VCPU",            0x1398},
    {"0450_HV_VCPU_CPUID",      0x128},
    {"0450_VMSPACE_VM_VMID",         0},  // TODO
    {"0450_VMSPACE_VM_PMAP",         0},  // TODO
    {"0450_PMAP_PM_PML4",         0x028},
    {"0450_DATA_BASE_GVMSPACE", 0x064C3F80},
    {"0450_KERNEL_OFF_CODE_CAVE",    0x0044000},
    {"0450_PPR_SYSENT",        0x0D709C0},
    {"0450_GADGET_JMP_PTR_RSI",  0x0042000},

    // FW 4.51
    {"0451_KDATA_OFFSET",       0x0C00000},
    {"0451_OFF_DMPML4I",       0x3E57D00},
    {"0451_OFF_DMPDPI",        0x3E57D04},
    {"0451_OFF_PML4PML4I",     0x3E57A5C},
    {"0451_OFF_PMAP_STORE",    0x3E57A78},
    {"0451_OFF_ALLPROC",       0x33EDCB8},
    {"0451_KERNEL_TEXT_SIZE",  0x0C00000},
    {"0451_HV_VCPU",            0x1398},
    {"0451_HV_VCPU_CPUID",      0x128},
    {"0451_VMSPACE_VM_VMID",         0},  // TODO
    {"0451_VMSPACE_VM_PMAP",         0},  // TODO
    {"0451_PMAP_PM_PML4",         0x028},
    {"0451_DATA_BASE_GVMSPACE", 0x064C3F80},
    {"0451_KERNEL_OFF_CODE_CAVE",    0x0044000},
    {"0451_PPR_SYSENT",        0x0D709C0},
    {"0451_GADGET_JMP_PTR_RSI",  0x0042000},
};

static inline uint64_t fw_off(uint32_t fw, const char *name) {
    auto key = std::format("{:04x}_{}", fw, name);
    auto it = fw_offsets.find(key);
    if (it == fw_offsets.end()) return 0;
    return it->second;
}

static inline bool fw_supported(uint32_t fw) {
    return fw_off(fw, "KDATA_OFFSET") != 0;
}
