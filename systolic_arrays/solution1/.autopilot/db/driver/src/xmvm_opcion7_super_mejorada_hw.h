// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// control
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read/COR)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read)
//        bit 7  - auto_restart (Read/Write)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0  - enable ap_done interrupt (Read/Write)
//        bit 1  - enable ap_ready interrupt (Read/Write)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/TOW)
//        bit 0  - ap_done (COR/TOW)
//        bit 1  - ap_ready (COR/TOW)
//        others - reserved
// 0x10 : Data signal of input1
//        bit 31~0 - input1[31:0] (Read/Write)
// 0x14 : Data signal of input1
//        bit 31~0 - input1[63:32] (Read/Write)
// 0x18 : reserved
// 0x1c : Data signal of input2
//        bit 31~0 - input2[31:0] (Read/Write)
// 0x20 : Data signal of input2
//        bit 31~0 - input2[63:32] (Read/Write)
// 0x24 : reserved
// 0x28 : Data signal of output_r
//        bit 31~0 - output_r[31:0] (Read/Write)
// 0x2c : Data signal of output_r
//        bit 31~0 - output_r[63:32] (Read/Write)
// 0x30 : reserved
// 0x34 : Data signal of MM
//        bit 31~0 - MM[31:0] (Read/Write)
// 0x38 : reserved
// 0x3c : Data signal of NN
//        bit 31~0 - NN[31:0] (Read/Write)
// 0x40 : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_AP_CTRL       0x00
#define XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_GIE           0x04
#define XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_IER           0x08
#define XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_ISR           0x0c
#define XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_INPUT1_DATA   0x10
#define XMVM_OPCION7_SUPER_MEJORADA_CONTROL_BITS_INPUT1_DATA   64
#define XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_INPUT2_DATA   0x1c
#define XMVM_OPCION7_SUPER_MEJORADA_CONTROL_BITS_INPUT2_DATA   64
#define XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_OUTPUT_R_DATA 0x28
#define XMVM_OPCION7_SUPER_MEJORADA_CONTROL_BITS_OUTPUT_R_DATA 64
#define XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_MM_DATA       0x34
#define XMVM_OPCION7_SUPER_MEJORADA_CONTROL_BITS_MM_DATA       32
#define XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_NN_DATA       0x3c
#define XMVM_OPCION7_SUPER_MEJORADA_CONTROL_BITS_NN_DATA       32

