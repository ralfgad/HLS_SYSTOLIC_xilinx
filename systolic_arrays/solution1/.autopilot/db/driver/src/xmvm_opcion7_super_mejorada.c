// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xmvm_opcion7_super_mejorada.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XMvm_opcion7_super_mejorada_CfgInitialize(XMvm_opcion7_super_mejorada *InstancePtr, XMvm_opcion7_super_mejorada_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XMvm_opcion7_super_mejorada_Start(XMvm_opcion7_super_mejorada *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMvm_opcion7_super_mejorada_ReadReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_AP_CTRL) & 0x80;
    XMvm_opcion7_super_mejorada_WriteReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XMvm_opcion7_super_mejorada_IsDone(XMvm_opcion7_super_mejorada *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMvm_opcion7_super_mejorada_ReadReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XMvm_opcion7_super_mejorada_IsIdle(XMvm_opcion7_super_mejorada *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMvm_opcion7_super_mejorada_ReadReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XMvm_opcion7_super_mejorada_IsReady(XMvm_opcion7_super_mejorada *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMvm_opcion7_super_mejorada_ReadReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XMvm_opcion7_super_mejorada_EnableAutoRestart(XMvm_opcion7_super_mejorada *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMvm_opcion7_super_mejorada_WriteReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XMvm_opcion7_super_mejorada_DisableAutoRestart(XMvm_opcion7_super_mejorada *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMvm_opcion7_super_mejorada_WriteReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_AP_CTRL, 0);
}

void XMvm_opcion7_super_mejorada_Set_input1(XMvm_opcion7_super_mejorada *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMvm_opcion7_super_mejorada_WriteReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_INPUT1_DATA, (u32)(Data));
    XMvm_opcion7_super_mejorada_WriteReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_INPUT1_DATA + 4, (u32)(Data >> 32));
}

u64 XMvm_opcion7_super_mejorada_Get_input1(XMvm_opcion7_super_mejorada *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMvm_opcion7_super_mejorada_ReadReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_INPUT1_DATA);
    Data += (u64)XMvm_opcion7_super_mejorada_ReadReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_INPUT1_DATA + 4) << 32;
    return Data;
}

void XMvm_opcion7_super_mejorada_Set_input2(XMvm_opcion7_super_mejorada *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMvm_opcion7_super_mejorada_WriteReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_INPUT2_DATA, (u32)(Data));
    XMvm_opcion7_super_mejorada_WriteReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_INPUT2_DATA + 4, (u32)(Data >> 32));
}

u64 XMvm_opcion7_super_mejorada_Get_input2(XMvm_opcion7_super_mejorada *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMvm_opcion7_super_mejorada_ReadReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_INPUT2_DATA);
    Data += (u64)XMvm_opcion7_super_mejorada_ReadReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_INPUT2_DATA + 4) << 32;
    return Data;
}

void XMvm_opcion7_super_mejorada_Set_output_r(XMvm_opcion7_super_mejorada *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMvm_opcion7_super_mejorada_WriteReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_OUTPUT_R_DATA, (u32)(Data));
    XMvm_opcion7_super_mejorada_WriteReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_OUTPUT_R_DATA + 4, (u32)(Data >> 32));
}

u64 XMvm_opcion7_super_mejorada_Get_output_r(XMvm_opcion7_super_mejorada *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMvm_opcion7_super_mejorada_ReadReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_OUTPUT_R_DATA);
    Data += (u64)XMvm_opcion7_super_mejorada_ReadReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_OUTPUT_R_DATA + 4) << 32;
    return Data;
}

void XMvm_opcion7_super_mejorada_Set_MM(XMvm_opcion7_super_mejorada *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMvm_opcion7_super_mejorada_WriteReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_MM_DATA, Data);
}

u32 XMvm_opcion7_super_mejorada_Get_MM(XMvm_opcion7_super_mejorada *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMvm_opcion7_super_mejorada_ReadReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_MM_DATA);
    return Data;
}

void XMvm_opcion7_super_mejorada_Set_NN(XMvm_opcion7_super_mejorada *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMvm_opcion7_super_mejorada_WriteReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_NN_DATA, Data);
}

u32 XMvm_opcion7_super_mejorada_Get_NN(XMvm_opcion7_super_mejorada *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMvm_opcion7_super_mejorada_ReadReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_NN_DATA);
    return Data;
}

void XMvm_opcion7_super_mejorada_InterruptGlobalEnable(XMvm_opcion7_super_mejorada *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMvm_opcion7_super_mejorada_WriteReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_GIE, 1);
}

void XMvm_opcion7_super_mejorada_InterruptGlobalDisable(XMvm_opcion7_super_mejorada *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMvm_opcion7_super_mejorada_WriteReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_GIE, 0);
}

void XMvm_opcion7_super_mejorada_InterruptEnable(XMvm_opcion7_super_mejorada *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMvm_opcion7_super_mejorada_ReadReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_IER);
    XMvm_opcion7_super_mejorada_WriteReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_IER, Register | Mask);
}

void XMvm_opcion7_super_mejorada_InterruptDisable(XMvm_opcion7_super_mejorada *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMvm_opcion7_super_mejorada_ReadReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_IER);
    XMvm_opcion7_super_mejorada_WriteReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_IER, Register & (~Mask));
}

void XMvm_opcion7_super_mejorada_InterruptClear(XMvm_opcion7_super_mejorada *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMvm_opcion7_super_mejorada_WriteReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_ISR, Mask);
}

u32 XMvm_opcion7_super_mejorada_InterruptGetEnabled(XMvm_opcion7_super_mejorada *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMvm_opcion7_super_mejorada_ReadReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_IER);
}

u32 XMvm_opcion7_super_mejorada_InterruptGetStatus(XMvm_opcion7_super_mejorada *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMvm_opcion7_super_mejorada_ReadReg(InstancePtr->Control_BaseAddress, XMVM_OPCION7_SUPER_MEJORADA_CONTROL_ADDR_ISR);
}

