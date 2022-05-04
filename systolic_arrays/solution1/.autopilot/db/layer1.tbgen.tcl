set moduleName layer1
set isTopModule 0
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {layer1}
set C_modelType { void 0 }
set C_modelArgList {
	{ aa int 32 regular {fifo 0 volatile }  }
	{ bb1 int 32 regular {fifo 0 volatile }  }
	{ ss int 32 regular {fifo 1 volatile }  }
	{ DESTINO int 32 regular {fifo 0}  }
	{ ORIGEN int 32 regular {fifo 0}  }
	{ DESTINO_out int 32 regular {fifo 1}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "aa", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "bb1", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "ss", "interface" : "fifo", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "DESTINO", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "ORIGEN", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "DESTINO_out", "interface" : "fifo", "bitwidth" : 32, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 25
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_continue sc_in sc_logic 1 continue -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ aa_dout sc_in sc_lv 32 signal 0 } 
	{ aa_empty_n sc_in sc_logic 1 signal 0 } 
	{ aa_read sc_out sc_logic 1 signal 0 } 
	{ bb1_dout sc_in sc_lv 32 signal 1 } 
	{ bb1_empty_n sc_in sc_logic 1 signal 1 } 
	{ bb1_read sc_out sc_logic 1 signal 1 } 
	{ ss_din sc_out sc_lv 32 signal 2 } 
	{ ss_full_n sc_in sc_logic 1 signal 2 } 
	{ ss_write sc_out sc_logic 1 signal 2 } 
	{ DESTINO_dout sc_in sc_lv 32 signal 3 } 
	{ DESTINO_empty_n sc_in sc_logic 1 signal 3 } 
	{ DESTINO_read sc_out sc_logic 1 signal 3 } 
	{ ORIGEN_dout sc_in sc_lv 32 signal 4 } 
	{ ORIGEN_empty_n sc_in sc_logic 1 signal 4 } 
	{ ORIGEN_read sc_out sc_logic 1 signal 4 } 
	{ DESTINO_out_din sc_out sc_lv 32 signal 5 } 
	{ DESTINO_out_full_n sc_in sc_logic 1 signal 5 } 
	{ DESTINO_out_write sc_out sc_logic 1 signal 5 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_continue", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "continue", "bundle":{"name": "ap_continue", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "aa_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "aa", "role": "dout" }} , 
 	{ "name": "aa_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "aa", "role": "empty_n" }} , 
 	{ "name": "aa_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "aa", "role": "read" }} , 
 	{ "name": "bb1_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "bb1", "role": "dout" }} , 
 	{ "name": "bb1_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "bb1", "role": "empty_n" }} , 
 	{ "name": "bb1_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "bb1", "role": "read" }} , 
 	{ "name": "ss_din", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "ss", "role": "din" }} , 
 	{ "name": "ss_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ss", "role": "full_n" }} , 
 	{ "name": "ss_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ss", "role": "write" }} , 
 	{ "name": "DESTINO_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "DESTINO", "role": "dout" }} , 
 	{ "name": "DESTINO_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "DESTINO", "role": "empty_n" }} , 
 	{ "name": "DESTINO_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "DESTINO", "role": "read" }} , 
 	{ "name": "ORIGEN_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "ORIGEN", "role": "dout" }} , 
 	{ "name": "ORIGEN_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ORIGEN", "role": "empty_n" }} , 
 	{ "name": "ORIGEN_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ORIGEN", "role": "read" }} , 
 	{ "name": "DESTINO_out_din", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "DESTINO_out", "role": "din" }} , 
 	{ "name": "DESTINO_out_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "DESTINO_out", "role": "full_n" }} , 
 	{ "name": "DESTINO_out_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "DESTINO_out", "role": "write" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8"],
		"CDFG" : "layer1",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "1", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "1",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "aa", "Type" : "Fifo", "Direction" : "I", "DependentProc" : "0", "DependentChan" : "0", "DependentChanDepth" : "2", "DependentChanType" : "0",
				"BlockSignal" : [
					{"Name" : "aa_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "bb1", "Type" : "Fifo", "Direction" : "I", "DependentProc" : "0", "DependentChan" : "0", "DependentChanDepth" : "2", "DependentChanType" : "0",
				"BlockSignal" : [
					{"Name" : "bb1_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "ss", "Type" : "Fifo", "Direction" : "O", "DependentProc" : "0", "DependentChan" : "0", "DependentChanDepth" : "2", "DependentChanType" : "0",
				"BlockSignal" : [
					{"Name" : "ss_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "DESTINO", "Type" : "Fifo", "Direction" : "I", "DependentProc" : "0", "DependentChan" : "0", "DependentChanDepth" : "2", "DependentChanType" : "2",
				"BlockSignal" : [
					{"Name" : "DESTINO_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "ORIGEN", "Type" : "Fifo", "Direction" : "I", "DependentProc" : "0", "DependentChan" : "0", "DependentChanDepth" : "2", "DependentChanType" : "2",
				"BlockSignal" : [
					{"Name" : "ORIGEN_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "DESTINO_out", "Type" : "Fifo", "Direction" : "O", "DependentProc" : "0", "DependentChan" : "0", "DependentChanDepth" : "2", "DependentChanType" : "2",
				"BlockSignal" : [
					{"Name" : "DESTINO_out_blk_n", "Type" : "RtlSignal"}]}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fadd_32ns_32ns_32_5_full_dsp_1_U16", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fmul_32ns_32ns_32_4_max_dsp_1_U17", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fptrunc_64ns_32_2_no_dsp_1_U18", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fpext_32ns_64_2_no_dsp_1_U19", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dsub_64ns_64ns_64_7_full_dsp_1_U20", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dadd_64ns_64ns_64_7_full_dsp_1_U21", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.ddiv_64ns_64ns_64_59_no_dsp_1_U22", "Parent" : "0"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dexp_64ns_64ns_64_21_full_dsp_1_U23", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	layer1 {
		aa {Type I LastRead 3 FirstWrite -1}
		bb1 {Type I LastRead 3 FirstWrite -1}
		ss {Type O LastRead -1 FirstWrite 98}
		DESTINO {Type I LastRead 0 FirstWrite -1}
		ORIGEN {Type I LastRead 0 FirstWrite -1}
		DESTINO_out {Type O LastRead -1 FirstWrite 0}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "-1", "Max" : "-1"}
	, {"Name" : "Interval", "Min" : "-1", "Max" : "-1"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	aa { ap_fifo {  { aa_dout fifo_data 0 32 }  { aa_empty_n fifo_status 0 1 }  { aa_read fifo_update 1 1 } } }
	bb1 { ap_fifo {  { bb1_dout fifo_data 0 32 }  { bb1_empty_n fifo_status 0 1 }  { bb1_read fifo_update 1 1 } } }
	ss { ap_fifo {  { ss_din fifo_data 1 32 }  { ss_full_n fifo_status 0 1 }  { ss_write fifo_update 1 1 } } }
	DESTINO { ap_fifo {  { DESTINO_dout fifo_data 0 32 }  { DESTINO_empty_n fifo_status 0 1 }  { DESTINO_read fifo_update 1 1 } } }
	ORIGEN { ap_fifo {  { ORIGEN_dout fifo_data 0 32 }  { ORIGEN_empty_n fifo_status 0 1 }  { ORIGEN_read fifo_update 1 1 } } }
	DESTINO_out { ap_fifo {  { DESTINO_out_din fifo_data 1 32 }  { DESTINO_out_full_n fifo_status 0 1 }  { DESTINO_out_write fifo_update 1 1 } } }
}
