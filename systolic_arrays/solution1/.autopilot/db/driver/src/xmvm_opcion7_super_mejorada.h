// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XMVM_OPCION7_SUPER_MEJORADA_H
#define XMVM_OPCION7_SUPER_MEJORADA_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xmvm_opcion7_super_mejorada_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
    u16 DeviceId;
    u32 Control_BaseAddress;
} XMvm_opcion7_super_mejorada_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XMvm_opcion7_super_mejorada;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XMvm_opcion7_super_mejorada_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XMvm_opcion7_super_mejorada_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XMvm_opcion7_super_mejorada_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XMvm_opcion7_super_mejorada_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XMvm_opcion7_super_mejorada_Initialize(XMvm_opcion7_super_mejorada *InstancePtr, u16 DeviceId);
XMvm_opcion7_super_mejorada_Config* XMvm_opcion7_super_mejorada_LookupConfig(u16 DeviceId);
int XMvm_opcion7_super_mejorada_CfgInitialize(XMvm_opcion7_super_mejorada *InstancePtr, XMvm_opcion7_super_mejorada_Config *ConfigPtr);
#else
int XMvm_opcion7_super_mejorada_Initialize(XMvm_opcion7_super_mejorada *InstancePtr, const char* InstanceName);
int XMvm_opcion7_super_mejorada_Release(XMvm_opcion7_super_mejorada *InstancePtr);
#endif

void XMvm_opcion7_super_mejorada_Start(XMvm_opcion7_super_mejorada *InstancePtr);
u32 XMvm_opcion7_super_mejorada_IsDone(XMvm_opcion7_super_mejorada *InstancePtr);
u32 XMvm_opcion7_super_mejorada_IsIdle(XMvm_opcion7_super_mejorada *InstancePtr);
u32 XMvm_opcion7_super_mejorada_IsReady(XMvm_opcion7_super_mejorada *InstancePtr);
void XMvm_opcion7_super_mejorada_EnableAutoRestart(XMvm_opcion7_super_mejorada *InstancePtr);
void XMvm_opcion7_super_mejorada_DisableAutoRestart(XMvm_opcion7_super_mejorada *InstancePtr);

void XMvm_opcion7_super_mejorada_Set_input1(XMvm_opcion7_super_mejorada *InstancePtr, u64 Data);
u64 XMvm_opcion7_super_mejorada_Get_input1(XMvm_opcion7_super_mejorada *InstancePtr);
void XMvm_opcion7_super_mejorada_Set_input2(XMvm_opcion7_super_mejorada *InstancePtr, u64 Data);
u64 XMvm_opcion7_super_mejorada_Get_input2(XMvm_opcion7_super_mejorada *InstancePtr);
void XMvm_opcion7_super_mejorada_Set_output_r(XMvm_opcion7_super_mejorada *InstancePtr, u64 Data);
u64 XMvm_opcion7_super_mejorada_Get_output_r(XMvm_opcion7_super_mejorada *InstancePtr);
void XMvm_opcion7_super_mejorada_Set_MM(XMvm_opcion7_super_mejorada *InstancePtr, u32 Data);
u32 XMvm_opcion7_super_mejorada_Get_MM(XMvm_opcion7_super_mejorada *InstancePtr);
void XMvm_opcion7_super_mejorada_Set_NN(XMvm_opcion7_super_mejorada *InstancePtr, u32 Data);
u32 XMvm_opcion7_super_mejorada_Get_NN(XMvm_opcion7_super_mejorada *InstancePtr);

void XMvm_opcion7_super_mejorada_InterruptGlobalEnable(XMvm_opcion7_super_mejorada *InstancePtr);
void XMvm_opcion7_super_mejorada_InterruptGlobalDisable(XMvm_opcion7_super_mejorada *InstancePtr);
void XMvm_opcion7_super_mejorada_InterruptEnable(XMvm_opcion7_super_mejorada *InstancePtr, u32 Mask);
void XMvm_opcion7_super_mejorada_InterruptDisable(XMvm_opcion7_super_mejorada *InstancePtr, u32 Mask);
void XMvm_opcion7_super_mejorada_InterruptClear(XMvm_opcion7_super_mejorada *InstancePtr, u32 Mask);
u32 XMvm_opcion7_super_mejorada_InterruptGetEnabled(XMvm_opcion7_super_mejorada *InstancePtr);
u32 XMvm_opcion7_super_mejorada_InterruptGetStatus(XMvm_opcion7_super_mejorada *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
