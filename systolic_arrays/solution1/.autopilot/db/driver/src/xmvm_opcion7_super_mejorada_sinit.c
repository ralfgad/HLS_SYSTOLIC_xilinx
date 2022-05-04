// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xmvm_opcion7_super_mejorada.h"

extern XMvm_opcion7_super_mejorada_Config XMvm_opcion7_super_mejorada_ConfigTable[];

XMvm_opcion7_super_mejorada_Config *XMvm_opcion7_super_mejorada_LookupConfig(u16 DeviceId) {
	XMvm_opcion7_super_mejorada_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XMVM_OPCION7_SUPER_MEJORADA_NUM_INSTANCES; Index++) {
		if (XMvm_opcion7_super_mejorada_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XMvm_opcion7_super_mejorada_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XMvm_opcion7_super_mejorada_Initialize(XMvm_opcion7_super_mejorada *InstancePtr, u16 DeviceId) {
	XMvm_opcion7_super_mejorada_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XMvm_opcion7_super_mejorada_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XMvm_opcion7_super_mejorada_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

