############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project modelo18
set_top MVM_opcion_sistolica
add_files Mis_tasks_mejora_grano_fino_V_H_V_best21.cpp
add_files -tb test_dataflow_modelo18.cpp
open_solution "solution1" -flow_target vivado
set_part {xc7z010iclg225-1L}
create_clock -period 10 -name default
source "./modelo18/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
