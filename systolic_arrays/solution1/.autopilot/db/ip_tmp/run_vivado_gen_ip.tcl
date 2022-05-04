create_project prj -part xc7z020-clg400-1 -force
set_property target_language verilog [current_project]
set vivado_ver [version -short]
set COE_DIR "../../syn/verilog"
source "/home/rgadea/pruebas_HLS_XILINX_2022/rgadea/systolic_arrays/solution1/syn/verilog/MVM_opcion7_super_mejorada_ap_ddiv_57_no_dsp_64_ip.tcl"
source "/home/rgadea/pruebas_HLS_XILINX_2022/rgadea/systolic_arrays/solution1/syn/verilog/MVM_opcion7_super_mejorada_ap_dsub_5_full_dsp_64_ip.tcl"
source "/home/rgadea/pruebas_HLS_XILINX_2022/rgadea/systolic_arrays/solution1/syn/verilog/MVM_opcion7_super_mejorada_ap_fmul_2_max_dsp_32_ip.tcl"
source "/home/rgadea/pruebas_HLS_XILINX_2022/rgadea/systolic_arrays/solution1/syn/verilog/MVM_opcion7_super_mejorada_ap_dadd_5_full_dsp_64_ip.tcl"
source "/home/rgadea/pruebas_HLS_XILINX_2022/rgadea/systolic_arrays/solution1/syn/verilog/MVM_opcion7_super_mejorada_ap_fptrunc_0_no_dsp_64_ip.tcl"
source "/home/rgadea/pruebas_HLS_XILINX_2022/rgadea/systolic_arrays/solution1/syn/verilog/MVM_opcion7_super_mejorada_ap_dexp_19_full_dsp_64_ip.tcl"
source "/home/rgadea/pruebas_HLS_XILINX_2022/rgadea/systolic_arrays/solution1/syn/verilog/MVM_opcion7_super_mejorada_ap_fpext_0_no_dsp_32_ip.tcl"
source "/home/rgadea/pruebas_HLS_XILINX_2022/rgadea/systolic_arrays/solution1/syn/verilog/MVM_opcion7_super_mejorada_ap_fadd_3_full_dsp_32_ip.tcl"
