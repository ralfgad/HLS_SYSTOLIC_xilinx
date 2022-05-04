
/opt/Xilinx/Vivado/2020.2/bin/xelab xil_defaultlib.apatb_MVM_opcion7_super_mejorada_top glbl -prj MVM_opcion7_super_mejorada.prj -L smartconnect_v1_0 -L axi_protocol_checker_v1_1_12 -L axi_protocol_checker_v1_1_13 -L axis_protocol_checker_v1_1_11 -L axis_protocol_checker_v1_1_12 -L xil_defaultlib -L unisims_ver -L xpm  -L floating_point_v7_0_18 -L floating_point_v7_1_11 --lib "ieee_proposed=./ieee_proposed" -s MVM_opcion7_super_mejorada -debug wave
/opt/Xilinx/Vivado/2020.2/bin/xsim --noieeewarnings MVM_opcion7_super_mejorada -tclbatch MVM_opcion7_super_mejorada.tcl -view MVM_opcion7_super_mejorada_dataflow_ana.wcfg -protoinst MVM_opcion7_super_mejorada.protoinst

