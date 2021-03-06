// ==============================================================
// RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Version: 2020.2
// Copyright (C) Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

module MVM_opcion7_super_mejorada_layer1 (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_continue,
        ap_idle,
        ap_ready,
        aa_dout,
        aa_empty_n,
        aa_read,
        bb1_dout,
        bb1_empty_n,
        bb1_read,
        ss_din,
        ss_full_n,
        ss_write,
        DESTINO_dout,
        DESTINO_empty_n,
        DESTINO_read,
        ORIGEN_dout,
        ORIGEN_empty_n,
        ORIGEN_read,
        DESTINO_out_din,
        DESTINO_out_full_n,
        DESTINO_out_write
);

parameter    ap_ST_fsm_state1 = 102'd1;
parameter    ap_ST_fsm_state2 = 102'd2;
parameter    ap_ST_fsm_pp0_stage0 = 102'd4;
parameter    ap_ST_fsm_pp0_stage1 = 102'd8;
parameter    ap_ST_fsm_pp0_stage2 = 102'd16;
parameter    ap_ST_fsm_pp0_stage3 = 102'd32;
parameter    ap_ST_fsm_state14 = 102'd64;
parameter    ap_ST_fsm_state15 = 102'd128;
parameter    ap_ST_fsm_state16 = 102'd256;
parameter    ap_ST_fsm_state17 = 102'd512;
parameter    ap_ST_fsm_state18 = 102'd1024;
parameter    ap_ST_fsm_state19 = 102'd2048;
parameter    ap_ST_fsm_state20 = 102'd4096;
parameter    ap_ST_fsm_state21 = 102'd8192;
parameter    ap_ST_fsm_state22 = 102'd16384;
parameter    ap_ST_fsm_state23 = 102'd32768;
parameter    ap_ST_fsm_state24 = 102'd65536;
parameter    ap_ST_fsm_state25 = 102'd131072;
parameter    ap_ST_fsm_state26 = 102'd262144;
parameter    ap_ST_fsm_state27 = 102'd524288;
parameter    ap_ST_fsm_state28 = 102'd1048576;
parameter    ap_ST_fsm_state29 = 102'd2097152;
parameter    ap_ST_fsm_state30 = 102'd4194304;
parameter    ap_ST_fsm_state31 = 102'd8388608;
parameter    ap_ST_fsm_state32 = 102'd16777216;
parameter    ap_ST_fsm_state33 = 102'd33554432;
parameter    ap_ST_fsm_state34 = 102'd67108864;
parameter    ap_ST_fsm_state35 = 102'd134217728;
parameter    ap_ST_fsm_state36 = 102'd268435456;
parameter    ap_ST_fsm_state37 = 102'd536870912;
parameter    ap_ST_fsm_state38 = 102'd1073741824;
parameter    ap_ST_fsm_state39 = 102'd2147483648;
parameter    ap_ST_fsm_state40 = 102'd4294967296;
parameter    ap_ST_fsm_state41 = 102'd8589934592;
parameter    ap_ST_fsm_state42 = 102'd17179869184;
parameter    ap_ST_fsm_state43 = 102'd34359738368;
parameter    ap_ST_fsm_state44 = 102'd68719476736;
parameter    ap_ST_fsm_state45 = 102'd137438953472;
parameter    ap_ST_fsm_state46 = 102'd274877906944;
parameter    ap_ST_fsm_state47 = 102'd549755813888;
parameter    ap_ST_fsm_state48 = 102'd1099511627776;
parameter    ap_ST_fsm_state49 = 102'd2199023255552;
parameter    ap_ST_fsm_state50 = 102'd4398046511104;
parameter    ap_ST_fsm_state51 = 102'd8796093022208;
parameter    ap_ST_fsm_state52 = 102'd17592186044416;
parameter    ap_ST_fsm_state53 = 102'd35184372088832;
parameter    ap_ST_fsm_state54 = 102'd70368744177664;
parameter    ap_ST_fsm_state55 = 102'd140737488355328;
parameter    ap_ST_fsm_state56 = 102'd281474976710656;
parameter    ap_ST_fsm_state57 = 102'd562949953421312;
parameter    ap_ST_fsm_state58 = 102'd1125899906842624;
parameter    ap_ST_fsm_state59 = 102'd2251799813685248;
parameter    ap_ST_fsm_state60 = 102'd4503599627370496;
parameter    ap_ST_fsm_state61 = 102'd9007199254740992;
parameter    ap_ST_fsm_state62 = 102'd18014398509481984;
parameter    ap_ST_fsm_state63 = 102'd36028797018963968;
parameter    ap_ST_fsm_state64 = 102'd72057594037927936;
parameter    ap_ST_fsm_state65 = 102'd144115188075855872;
parameter    ap_ST_fsm_state66 = 102'd288230376151711744;
parameter    ap_ST_fsm_state67 = 102'd576460752303423488;
parameter    ap_ST_fsm_state68 = 102'd1152921504606846976;
parameter    ap_ST_fsm_state69 = 102'd2305843009213693952;
parameter    ap_ST_fsm_state70 = 102'd4611686018427387904;
parameter    ap_ST_fsm_state71 = 102'd9223372036854775808;
parameter    ap_ST_fsm_state72 = 102'd18446744073709551616;
parameter    ap_ST_fsm_state73 = 102'd36893488147419103232;
parameter    ap_ST_fsm_state74 = 102'd73786976294838206464;
parameter    ap_ST_fsm_state75 = 102'd147573952589676412928;
parameter    ap_ST_fsm_state76 = 102'd295147905179352825856;
parameter    ap_ST_fsm_state77 = 102'd590295810358705651712;
parameter    ap_ST_fsm_state78 = 102'd1180591620717411303424;
parameter    ap_ST_fsm_state79 = 102'd2361183241434822606848;
parameter    ap_ST_fsm_state80 = 102'd4722366482869645213696;
parameter    ap_ST_fsm_state81 = 102'd9444732965739290427392;
parameter    ap_ST_fsm_state82 = 102'd18889465931478580854784;
parameter    ap_ST_fsm_state83 = 102'd37778931862957161709568;
parameter    ap_ST_fsm_state84 = 102'd75557863725914323419136;
parameter    ap_ST_fsm_state85 = 102'd151115727451828646838272;
parameter    ap_ST_fsm_state86 = 102'd302231454903657293676544;
parameter    ap_ST_fsm_state87 = 102'd604462909807314587353088;
parameter    ap_ST_fsm_state88 = 102'd1208925819614629174706176;
parameter    ap_ST_fsm_state89 = 102'd2417851639229258349412352;
parameter    ap_ST_fsm_state90 = 102'd4835703278458516698824704;
parameter    ap_ST_fsm_state91 = 102'd9671406556917033397649408;
parameter    ap_ST_fsm_state92 = 102'd19342813113834066795298816;
parameter    ap_ST_fsm_state93 = 102'd38685626227668133590597632;
parameter    ap_ST_fsm_state94 = 102'd77371252455336267181195264;
parameter    ap_ST_fsm_state95 = 102'd154742504910672534362390528;
parameter    ap_ST_fsm_state96 = 102'd309485009821345068724781056;
parameter    ap_ST_fsm_state97 = 102'd618970019642690137449562112;
parameter    ap_ST_fsm_state98 = 102'd1237940039285380274899124224;
parameter    ap_ST_fsm_state99 = 102'd2475880078570760549798248448;
parameter    ap_ST_fsm_state100 = 102'd4951760157141521099596496896;
parameter    ap_ST_fsm_state101 = 102'd9903520314283042199192993792;
parameter    ap_ST_fsm_state102 = 102'd19807040628566084398385987584;
parameter    ap_ST_fsm_state103 = 102'd39614081257132168796771975168;
parameter    ap_ST_fsm_state104 = 102'd79228162514264337593543950336;
parameter    ap_ST_fsm_state105 = 102'd158456325028528675187087900672;
parameter    ap_ST_fsm_state106 = 102'd316912650057057350374175801344;
parameter    ap_ST_fsm_state107 = 102'd633825300114114700748351602688;
parameter    ap_ST_fsm_state108 = 102'd1267650600228229401496703205376;
parameter    ap_ST_fsm_state109 = 102'd2535301200456458802993406410752;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
input   ap_continue;
output   ap_idle;
output   ap_ready;
input  [31:0] aa_dout;
input   aa_empty_n;
output   aa_read;
input  [31:0] bb1_dout;
input   bb1_empty_n;
output   bb1_read;
output  [31:0] ss_din;
input   ss_full_n;
output   ss_write;
input  [31:0] DESTINO_dout;
input   DESTINO_empty_n;
output   DESTINO_read;
input  [31:0] ORIGEN_dout;
input   ORIGEN_empty_n;
output   ORIGEN_read;
output  [31:0] DESTINO_out_din;
input   DESTINO_out_full_n;
output   DESTINO_out_write;

reg ap_done;
reg ap_idle;
reg ap_ready;
reg aa_read;
reg bb1_read;
reg ss_write;
reg DESTINO_read;
reg ORIGEN_read;
reg DESTINO_out_write;

reg    ap_done_reg;
(* fsm_encoding = "none" *) reg   [101:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
reg    aa_blk_n;
wire    ap_CS_fsm_pp0_stage1;
reg    ap_enable_reg_pp0_iter0;
wire    ap_block_pp0_stage1;
reg   [0:0] icmp_ln878_1_reg_243;
reg    bb1_blk_n;
reg    ss_blk_n;
wire    ap_CS_fsm_state109;
reg    DESTINO_blk_n;
reg    ORIGEN_blk_n;
reg    DESTINO_out_blk_n;
reg   [31:0] temp_reg_112;
reg   [30:0] i_V_reg_124;
wire   [31:0] grp_fu_140_p2;
reg   [31:0] reg_171;
reg    ap_enable_reg_pp0_iter1;
reg    ap_block_state4_pp0_stage1_iter0;
wire    ap_block_state8_pp0_stage1_iter1;
wire    ap_block_state12_pp0_stage1_iter2;
reg    ap_block_pp0_stage1_11001;
reg   [0:0] icmp_ln878_1_reg_243_pp0_iter1_reg;
wire    ap_CS_fsm_state17;
reg   [31:0] DESTINO_read_reg_219;
reg   [31:0] ORIGEN_read_reg_224;
wire   [30:0] add_ln878_fu_177_p2;
reg   [30:0] add_ln878_reg_229;
wire    ap_CS_fsm_state2;
wire   [0:0] icmp_ln878_fu_187_p2;
wire   [30:0] i_V_1_fu_192_p2;
reg   [30:0] i_V_1_reg_238;
wire    ap_CS_fsm_pp0_stage0;
wire    ap_block_state3_pp0_stage0_iter0;
wire    ap_block_state7_pp0_stage0_iter1;
wire    ap_block_state11_pp0_stage0_iter2;
wire    ap_block_pp0_stage0_11001;
wire   [0:0] icmp_ln878_1_fu_202_p2;
reg   [0:0] icmp_ln878_1_reg_243_pp0_iter2_reg;
reg   [31:0] aa_read_reg_247;
reg   [31:0] bb1_read_reg_252;
wire   [31:0] tmp_fu_207_p1;
wire    ap_CS_fsm_pp0_stage2;
wire    ap_block_state5_pp0_stage2_iter0;
wire    ap_block_state9_pp0_stage2_iter1;
wire    ap_block_state13_pp0_stage2_iter2;
wire    ap_block_pp0_stage2_11001;
wire   [31:0] tmp_1_fu_211_p1;
wire   [31:0] grp_fu_135_p2;
reg    ap_enable_reg_pp0_iter2;
wire   [63:0] grp_fu_149_p1;
reg   [63:0] conv_i_i_reg_272;
wire    ap_CS_fsm_state19;
wire   [63:0] grp_fu_166_p2;
reg   [63:0] tmp_i_reg_277;
wire    ap_CS_fsm_state40;
wire   [63:0] grp_fu_152_p2;
reg   [63:0] sub_i_i_reg_283;
wire    ap_CS_fsm_state47;
wire   [63:0] grp_fu_157_p2;
reg   [63:0] add_i_i_reg_288;
wire   [63:0] grp_fu_162_p2;
reg   [63:0] div_i_i_reg_293;
wire    ap_CS_fsm_state106;
wire   [31:0] grp_fu_146_p1;
reg   [31:0] temp2_reg_298;
wire    ap_CS_fsm_state108;
wire    ap_block_pp0_stage0_subdone;
reg    ap_condition_pp0_exit_iter0_state3;
wire    ap_block_state6_pp0_stage3_iter0;
wire    ap_block_state10_pp0_stage3_iter1;
wire    ap_block_pp0_stage3_subdone;
wire    ap_CS_fsm_pp0_stage3;
wire    ap_block_pp0_stage2_subdone;
reg   [30:0] j_V_reg_101;
reg    ap_block_state1;
reg   [31:0] ap_phi_mux_temp_phi_fu_116_p4;
wire    ap_block_pp0_stage2;
reg   [30:0] ap_phi_mux_i_V_phi_fu_128_p4;
wire    ap_block_pp0_stage0;
reg   [31:0] grp_fu_140_p0;
reg   [31:0] grp_fu_140_p1;
wire    ap_CS_fsm_state14;
wire    ap_CS_fsm_state107;
wire    ap_CS_fsm_state18;
wire    ap_CS_fsm_state41;
wire    ap_CS_fsm_state48;
wire    ap_CS_fsm_state20;
wire   [31:0] zext_ln24_fu_183_p1;
wire   [31:0] i_V_cast_fu_198_p1;
reg    grp_fu_135_ce;
wire    ap_block_pp0_stage3_11001;
reg    grp_fu_140_ce;
wire    ap_CS_fsm_state15;
wire    ap_CS_fsm_state16;
reg   [101:0] ap_NS_fsm;
reg    ap_block_pp0_stage1_subdone;
reg    ap_idle_pp0;
wire    ap_enable_pp0;
wire    ap_ce_reg;

// power-on initialization
initial begin
#0 ap_done_reg = 1'b0;
#0 ap_CS_fsm = 102'd1;
#0 ap_enable_reg_pp0_iter0 = 1'b0;
#0 ap_enable_reg_pp0_iter1 = 1'b0;
#0 ap_enable_reg_pp0_iter2 = 1'b0;
end

MVM_opcion7_super_mejorada_fadd_32ns_32ns_32_5_full_dsp_1 #(
    .ID( 1 ),
    .NUM_STAGE( 5 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 32 ),
    .dout_WIDTH( 32 ))
fadd_32ns_32ns_32_5_full_dsp_1_U16(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(reg_171),
    .din1(ap_phi_mux_temp_phi_fu_116_p4),
    .ce(grp_fu_135_ce),
    .dout(grp_fu_135_p2)
);

MVM_opcion7_super_mejorada_fmul_32ns_32ns_32_4_max_dsp_1 #(
    .ID( 1 ),
    .NUM_STAGE( 4 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 32 ),
    .dout_WIDTH( 32 ))
fmul_32ns_32ns_32_4_max_dsp_1_U17(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(grp_fu_140_p0),
    .din1(grp_fu_140_p1),
    .ce(grp_fu_140_ce),
    .dout(grp_fu_140_p2)
);

MVM_opcion7_super_mejorada_fptrunc_64ns_32_2_no_dsp_1 #(
    .ID( 1 ),
    .NUM_STAGE( 2 ),
    .din0_WIDTH( 64 ),
    .dout_WIDTH( 32 ))
fptrunc_64ns_32_2_no_dsp_1_U18(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(div_i_i_reg_293),
    .ce(1'b1),
    .dout(grp_fu_146_p1)
);

MVM_opcion7_super_mejorada_fpext_32ns_64_2_no_dsp_1 #(
    .ID( 1 ),
    .NUM_STAGE( 2 ),
    .din0_WIDTH( 32 ),
    .dout_WIDTH( 64 ))
fpext_32ns_64_2_no_dsp_1_U19(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(reg_171),
    .ce(1'b1),
    .dout(grp_fu_149_p1)
);

MVM_opcion7_super_mejorada_dsub_64ns_64ns_64_7_full_dsp_1 #(
    .ID( 1 ),
    .NUM_STAGE( 7 ),
    .din0_WIDTH( 64 ),
    .din1_WIDTH( 64 ),
    .dout_WIDTH( 64 ))
dsub_64ns_64ns_64_7_full_dsp_1_U20(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(64'd4607182418800017408),
    .din1(tmp_i_reg_277),
    .ce(1'b1),
    .dout(grp_fu_152_p2)
);

MVM_opcion7_super_mejorada_dadd_64ns_64ns_64_7_full_dsp_1 #(
    .ID( 1 ),
    .NUM_STAGE( 7 ),
    .din0_WIDTH( 64 ),
    .din1_WIDTH( 64 ),
    .dout_WIDTH( 64 ))
dadd_64ns_64ns_64_7_full_dsp_1_U21(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(tmp_i_reg_277),
    .din1(64'd4607182418800017408),
    .ce(1'b1),
    .dout(grp_fu_157_p2)
);

MVM_opcion7_super_mejorada_ddiv_64ns_64ns_64_59_no_dsp_1 #(
    .ID( 1 ),
    .NUM_STAGE( 59 ),
    .din0_WIDTH( 64 ),
    .din1_WIDTH( 64 ),
    .dout_WIDTH( 64 ))
ddiv_64ns_64ns_64_59_no_dsp_1_U22(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(sub_i_i_reg_283),
    .din1(add_i_i_reg_288),
    .ce(1'b1),
    .dout(grp_fu_162_p2)
);

MVM_opcion7_super_mejorada_dexp_64ns_64ns_64_21_full_dsp_1 #(
    .ID( 1 ),
    .NUM_STAGE( 21 ),
    .din0_WIDTH( 64 ),
    .din1_WIDTH( 64 ),
    .dout_WIDTH( 64 ))
dexp_64ns_64ns_64_21_full_dsp_1_U23(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(64'd0),
    .din1(conv_i_i_reg_272),
    .ce(1'b1),
    .dout(grp_fu_166_p2)
);

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_done_reg <= 1'b0;
    end else begin
        if ((ap_continue == 1'b1)) begin
            ap_done_reg <= 1'b0;
        end else if (((icmp_ln878_fu_187_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
            ap_done_reg <= 1'b1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter0 <= 1'b0;
    end else begin
        if (((1'b1 == ap_condition_pp0_exit_iter0_state3) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_subdone))) begin
            ap_enable_reg_pp0_iter0 <= 1'b0;
        end else if (((icmp_ln878_fu_187_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
            ap_enable_reg_pp0_iter0 <= 1'b1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter1 <= 1'b0;
    end else begin
        if (((1'b1 == ap_CS_fsm_pp0_stage3) & (1'b0 == ap_block_pp0_stage3_subdone))) begin
            ap_enable_reg_pp0_iter1 <= ap_enable_reg_pp0_iter0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter2 <= 1'b0;
    end else begin
        if ((((1'b1 == ap_CS_fsm_pp0_stage3) & (1'b0 == ap_block_pp0_stage3_subdone)) | ((1'b1 == ap_CS_fsm_pp0_stage2) & (ap_enable_reg_pp0_iter1 == 1'b0) & (1'b0 == ap_block_pp0_stage2_subdone)))) begin
            ap_enable_reg_pp0_iter2 <= ap_enable_reg_pp0_iter1;
        end else if (((icmp_ln878_fu_187_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
            ap_enable_reg_pp0_iter2 <= 1'b0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage0) & (ap_enable_reg_pp0_iter1 == 1'b1) & (icmp_ln878_1_reg_243 == 1'd1) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        i_V_reg_124 <= i_V_1_reg_238;
    end else if (((icmp_ln878_fu_187_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        i_V_reg_124 <= 31'd0;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state109) & (ss_full_n == 1'b1))) begin
        j_V_reg_101 <= add_ln878_reg_229;
    end else if ((~((1'b0 == DESTINO_out_full_n) | (1'b0 == ORIGEN_empty_n) | (1'b0 == DESTINO_empty_n) | (ap_done_reg == 1'b1) | (ap_start == 1'b0)) & (1'b1 == ap_CS_fsm_state1))) begin
        j_V_reg_101 <= 31'd0;
    end
end

always @ (posedge ap_clk) begin
    if (((ap_enable_reg_pp0_iter2 == 1'b1) & (icmp_ln878_1_reg_243_pp0_iter2_reg == 1'd1) & (1'b1 == ap_CS_fsm_pp0_stage2) & (1'b0 == ap_block_pp0_stage2_11001))) begin
        temp_reg_112 <= grp_fu_135_p2;
    end else if (((icmp_ln878_fu_187_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        temp_reg_112 <= 32'd0;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state1)) begin
        DESTINO_read_reg_219 <= DESTINO_dout;
        ORIGEN_read_reg_224 <= ORIGEN_dout;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage1) & (icmp_ln878_1_reg_243 == 1'd1) & (1'b0 == ap_block_pp0_stage1_11001))) begin
        aa_read_reg_247 <= aa_dout;
        bb1_read_reg_252 <= bb1_dout;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state47)) begin
        add_i_i_reg_288 <= grp_fu_157_p2;
        sub_i_i_reg_283 <= grp_fu_152_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        add_ln878_reg_229 <= add_ln878_fu_177_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state19)) begin
        conv_i_i_reg_272 <= grp_fu_149_p1;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state106)) begin
        div_i_i_reg_293 <= grp_fu_162_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter0 == 1'b1))) begin
        i_V_1_reg_238 <= i_V_1_fu_192_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        icmp_ln878_1_reg_243 <= icmp_ln878_1_fu_202_p2;
        icmp_ln878_1_reg_243_pp0_iter1_reg <= icmp_ln878_1_reg_243;
        icmp_ln878_1_reg_243_pp0_iter2_reg <= icmp_ln878_1_reg_243_pp0_iter1_reg;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state17) | ((icmp_ln878_1_reg_243_pp0_iter1_reg == 1'd1) & (1'b1 == ap_CS_fsm_pp0_stage1) & (ap_enable_reg_pp0_iter1 == 1'b1) & (1'b0 == ap_block_pp0_stage1_11001)))) begin
        reg_171 <= grp_fu_140_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state108)) begin
        temp2_reg_298 <= grp_fu_146_p1;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state40)) begin
        tmp_i_reg_277 <= grp_fu_166_p2;
    end
end

always @ (*) begin
    if ((~((ap_done_reg == 1'b1) | (ap_start == 1'b0)) & (1'b1 == ap_CS_fsm_state1))) begin
        DESTINO_blk_n = DESTINO_empty_n;
    end else begin
        DESTINO_blk_n = 1'b1;
    end
end

always @ (*) begin
    if ((~((ap_done_reg == 1'b1) | (ap_start == 1'b0)) & (1'b1 == ap_CS_fsm_state1))) begin
        DESTINO_out_blk_n = DESTINO_out_full_n;
    end else begin
        DESTINO_out_blk_n = 1'b1;
    end
end

always @ (*) begin
    if ((~((1'b0 == DESTINO_out_full_n) | (1'b0 == ORIGEN_empty_n) | (1'b0 == DESTINO_empty_n) | (ap_done_reg == 1'b1) | (ap_start == 1'b0)) & (1'b1 == ap_CS_fsm_state1))) begin
        DESTINO_out_write = 1'b1;
    end else begin
        DESTINO_out_write = 1'b0;
    end
end

always @ (*) begin
    if ((~((1'b0 == DESTINO_out_full_n) | (1'b0 == ORIGEN_empty_n) | (1'b0 == DESTINO_empty_n) | (ap_done_reg == 1'b1) | (ap_start == 1'b0)) & (1'b1 == ap_CS_fsm_state1))) begin
        DESTINO_read = 1'b1;
    end else begin
        DESTINO_read = 1'b0;
    end
end

always @ (*) begin
    if ((~((ap_done_reg == 1'b1) | (ap_start == 1'b0)) & (1'b1 == ap_CS_fsm_state1))) begin
        ORIGEN_blk_n = ORIGEN_empty_n;
    end else begin
        ORIGEN_blk_n = 1'b1;
    end
end

always @ (*) begin
    if ((~((1'b0 == DESTINO_out_full_n) | (1'b0 == ORIGEN_empty_n) | (1'b0 == DESTINO_empty_n) | (ap_done_reg == 1'b1) | (ap_start == 1'b0)) & (1'b1 == ap_CS_fsm_state1))) begin
        ORIGEN_read = 1'b1;
    end else begin
        ORIGEN_read = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage1) & (icmp_ln878_1_reg_243 == 1'd1) & (1'b0 == ap_block_pp0_stage1) & (ap_enable_reg_pp0_iter0 == 1'b1))) begin
        aa_blk_n = aa_empty_n;
    end else begin
        aa_blk_n = 1'b1;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage1) & (icmp_ln878_1_reg_243 == 1'd1) & (1'b0 == ap_block_pp0_stage1_11001) & (ap_enable_reg_pp0_iter0 == 1'b1))) begin
        aa_read = 1'b1;
    end else begin
        aa_read = 1'b0;
    end
end

always @ (*) begin
    if ((icmp_ln878_1_fu_202_p2 == 1'd0)) begin
        ap_condition_pp0_exit_iter0_state3 = 1'b1;
    end else begin
        ap_condition_pp0_exit_iter0_state3 = 1'b0;
    end
end

always @ (*) begin
    if (((icmp_ln878_fu_187_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = ap_done_reg;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b0))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter2 == 1'b0) & (ap_enable_reg_pp0_iter1 == 1'b0) & (ap_enable_reg_pp0_iter0 == 1'b0))) begin
        ap_idle_pp0 = 1'b1;
    end else begin
        ap_idle_pp0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage0) & (ap_enable_reg_pp0_iter1 == 1'b1) & (icmp_ln878_1_reg_243 == 1'd1) & (1'b0 == ap_block_pp0_stage0))) begin
        ap_phi_mux_i_V_phi_fu_128_p4 = i_V_1_reg_238;
    end else begin
        ap_phi_mux_i_V_phi_fu_128_p4 = i_V_reg_124;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter2 == 1'b1) & (icmp_ln878_1_reg_243_pp0_iter2_reg == 1'd1) & (1'b1 == ap_CS_fsm_pp0_stage2) & (1'b0 == ap_block_pp0_stage2))) begin
        ap_phi_mux_temp_phi_fu_116_p4 = grp_fu_135_p2;
    end else begin
        ap_phi_mux_temp_phi_fu_116_p4 = temp_reg_112;
    end
end

always @ (*) begin
    if (((icmp_ln878_fu_187_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage1) & (icmp_ln878_1_reg_243 == 1'd1) & (1'b0 == ap_block_pp0_stage1) & (ap_enable_reg_pp0_iter0 == 1'b1))) begin
        bb1_blk_n = bb1_empty_n;
    end else begin
        bb1_blk_n = 1'b1;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage1) & (icmp_ln878_1_reg_243 == 1'd1) & (1'b0 == ap_block_pp0_stage1_11001) & (ap_enable_reg_pp0_iter0 == 1'b1))) begin
        bb1_read = 1'b1;
    end else begin
        bb1_read = 1'b0;
    end
end

always @ (*) begin
    if ((((1'b1 == ap_CS_fsm_pp0_stage3) & (1'b0 == ap_block_pp0_stage3_11001)) | ((1'b1 == ap_CS_fsm_pp0_stage2) & (1'b0 == ap_block_pp0_stage2_11001)) | ((1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001)) | ((1'b1 == ap_CS_fsm_pp0_stage1) & (1'b0 == ap_block_pp0_stage1_11001)))) begin
        grp_fu_135_ce = 1'b1;
    end else begin
        grp_fu_135_ce = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state16) | (1'b1 == ap_CS_fsm_state15) | (1'b1 == ap_CS_fsm_state14) | (1'b1 == ap_CS_fsm_state17) | ((1'b1 == ap_CS_fsm_pp0_stage3) & (1'b0 == ap_block_pp0_stage3_11001)) | ((1'b1 == ap_CS_fsm_pp0_stage2) & (1'b0 == ap_block_pp0_stage2_11001)) | ((1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001)) | ((1'b1 == ap_CS_fsm_pp0_stage1) & (1'b0 == ap_block_pp0_stage1_11001)))) begin
        grp_fu_140_ce = 1'b1;
    end else begin
        grp_fu_140_ce = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state14)) begin
        grp_fu_140_p0 = temp_reg_112;
    end else if (((1'b1 == ap_CS_fsm_pp0_stage2) & (1'b0 == ap_block_pp0_stage2) & (ap_enable_reg_pp0_iter0 == 1'b1))) begin
        grp_fu_140_p0 = tmp_fu_207_p1;
    end else begin
        grp_fu_140_p0 = 'bx;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state14)) begin
        grp_fu_140_p1 = 32'd3221225472;
    end else if (((1'b1 == ap_CS_fsm_pp0_stage2) & (1'b0 == ap_block_pp0_stage2) & (ap_enable_reg_pp0_iter0 == 1'b1))) begin
        grp_fu_140_p1 = tmp_1_fu_211_p1;
    end else begin
        grp_fu_140_p1 = 'bx;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state109)) begin
        ss_blk_n = ss_full_n;
    end else begin
        ss_blk_n = 1'b1;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state109) & (ss_full_n == 1'b1))) begin
        ss_write = 1'b1;
    end else begin
        ss_write = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if ((~((1'b0 == DESTINO_out_full_n) | (1'b0 == ORIGEN_empty_n) | (1'b0 == DESTINO_empty_n) | (ap_done_reg == 1'b1) | (ap_start == 1'b0)) & (1'b1 == ap_CS_fsm_state1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            if (((icmp_ln878_fu_187_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end
        end
        ap_ST_fsm_pp0_stage0 : begin
            if ((~((icmp_ln878_1_fu_202_p2 == 1'd0) & (ap_enable_reg_pp0_iter1 == 1'b0) & (1'b0 == ap_block_pp0_stage0_subdone) & (ap_enable_reg_pp0_iter0 == 1'b1)) & (1'b0 == ap_block_pp0_stage0_subdone))) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage1;
            end else if (((icmp_ln878_1_fu_202_p2 == 1'd0) & (ap_enable_reg_pp0_iter1 == 1'b0) & (1'b0 == ap_block_pp0_stage0_subdone) & (ap_enable_reg_pp0_iter0 == 1'b1))) begin
                ap_NS_fsm = ap_ST_fsm_state14;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end
        end
        ap_ST_fsm_pp0_stage1 : begin
            if ((1'b0 == ap_block_pp0_stage1_subdone)) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage1;
            end
        end
        ap_ST_fsm_pp0_stage2 : begin
            if ((~((ap_enable_reg_pp0_iter2 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage2) & (ap_enable_reg_pp0_iter1 == 1'b0) & (1'b0 == ap_block_pp0_stage2_subdone)) & (1'b0 == ap_block_pp0_stage2_subdone))) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage3;
            end else if (((ap_enable_reg_pp0_iter2 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage2) & (ap_enable_reg_pp0_iter1 == 1'b0) & (1'b0 == ap_block_pp0_stage2_subdone))) begin
                ap_NS_fsm = ap_ST_fsm_state14;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage2;
            end
        end
        ap_ST_fsm_pp0_stage3 : begin
            if ((1'b0 == ap_block_pp0_stage3_subdone)) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage3;
            end
        end
        ap_ST_fsm_state14 : begin
            ap_NS_fsm = ap_ST_fsm_state15;
        end
        ap_ST_fsm_state15 : begin
            ap_NS_fsm = ap_ST_fsm_state16;
        end
        ap_ST_fsm_state16 : begin
            ap_NS_fsm = ap_ST_fsm_state17;
        end
        ap_ST_fsm_state17 : begin
            ap_NS_fsm = ap_ST_fsm_state18;
        end
        ap_ST_fsm_state18 : begin
            ap_NS_fsm = ap_ST_fsm_state19;
        end
        ap_ST_fsm_state19 : begin
            ap_NS_fsm = ap_ST_fsm_state20;
        end
        ap_ST_fsm_state20 : begin
            ap_NS_fsm = ap_ST_fsm_state21;
        end
        ap_ST_fsm_state21 : begin
            ap_NS_fsm = ap_ST_fsm_state22;
        end
        ap_ST_fsm_state22 : begin
            ap_NS_fsm = ap_ST_fsm_state23;
        end
        ap_ST_fsm_state23 : begin
            ap_NS_fsm = ap_ST_fsm_state24;
        end
        ap_ST_fsm_state24 : begin
            ap_NS_fsm = ap_ST_fsm_state25;
        end
        ap_ST_fsm_state25 : begin
            ap_NS_fsm = ap_ST_fsm_state26;
        end
        ap_ST_fsm_state26 : begin
            ap_NS_fsm = ap_ST_fsm_state27;
        end
        ap_ST_fsm_state27 : begin
            ap_NS_fsm = ap_ST_fsm_state28;
        end
        ap_ST_fsm_state28 : begin
            ap_NS_fsm = ap_ST_fsm_state29;
        end
        ap_ST_fsm_state29 : begin
            ap_NS_fsm = ap_ST_fsm_state30;
        end
        ap_ST_fsm_state30 : begin
            ap_NS_fsm = ap_ST_fsm_state31;
        end
        ap_ST_fsm_state31 : begin
            ap_NS_fsm = ap_ST_fsm_state32;
        end
        ap_ST_fsm_state32 : begin
            ap_NS_fsm = ap_ST_fsm_state33;
        end
        ap_ST_fsm_state33 : begin
            ap_NS_fsm = ap_ST_fsm_state34;
        end
        ap_ST_fsm_state34 : begin
            ap_NS_fsm = ap_ST_fsm_state35;
        end
        ap_ST_fsm_state35 : begin
            ap_NS_fsm = ap_ST_fsm_state36;
        end
        ap_ST_fsm_state36 : begin
            ap_NS_fsm = ap_ST_fsm_state37;
        end
        ap_ST_fsm_state37 : begin
            ap_NS_fsm = ap_ST_fsm_state38;
        end
        ap_ST_fsm_state38 : begin
            ap_NS_fsm = ap_ST_fsm_state39;
        end
        ap_ST_fsm_state39 : begin
            ap_NS_fsm = ap_ST_fsm_state40;
        end
        ap_ST_fsm_state40 : begin
            ap_NS_fsm = ap_ST_fsm_state41;
        end
        ap_ST_fsm_state41 : begin
            ap_NS_fsm = ap_ST_fsm_state42;
        end
        ap_ST_fsm_state42 : begin
            ap_NS_fsm = ap_ST_fsm_state43;
        end
        ap_ST_fsm_state43 : begin
            ap_NS_fsm = ap_ST_fsm_state44;
        end
        ap_ST_fsm_state44 : begin
            ap_NS_fsm = ap_ST_fsm_state45;
        end
        ap_ST_fsm_state45 : begin
            ap_NS_fsm = ap_ST_fsm_state46;
        end
        ap_ST_fsm_state46 : begin
            ap_NS_fsm = ap_ST_fsm_state47;
        end
        ap_ST_fsm_state47 : begin
            ap_NS_fsm = ap_ST_fsm_state48;
        end
        ap_ST_fsm_state48 : begin
            ap_NS_fsm = ap_ST_fsm_state49;
        end
        ap_ST_fsm_state49 : begin
            ap_NS_fsm = ap_ST_fsm_state50;
        end
        ap_ST_fsm_state50 : begin
            ap_NS_fsm = ap_ST_fsm_state51;
        end
        ap_ST_fsm_state51 : begin
            ap_NS_fsm = ap_ST_fsm_state52;
        end
        ap_ST_fsm_state52 : begin
            ap_NS_fsm = ap_ST_fsm_state53;
        end
        ap_ST_fsm_state53 : begin
            ap_NS_fsm = ap_ST_fsm_state54;
        end
        ap_ST_fsm_state54 : begin
            ap_NS_fsm = ap_ST_fsm_state55;
        end
        ap_ST_fsm_state55 : begin
            ap_NS_fsm = ap_ST_fsm_state56;
        end
        ap_ST_fsm_state56 : begin
            ap_NS_fsm = ap_ST_fsm_state57;
        end
        ap_ST_fsm_state57 : begin
            ap_NS_fsm = ap_ST_fsm_state58;
        end
        ap_ST_fsm_state58 : begin
            ap_NS_fsm = ap_ST_fsm_state59;
        end
        ap_ST_fsm_state59 : begin
            ap_NS_fsm = ap_ST_fsm_state60;
        end
        ap_ST_fsm_state60 : begin
            ap_NS_fsm = ap_ST_fsm_state61;
        end
        ap_ST_fsm_state61 : begin
            ap_NS_fsm = ap_ST_fsm_state62;
        end
        ap_ST_fsm_state62 : begin
            ap_NS_fsm = ap_ST_fsm_state63;
        end
        ap_ST_fsm_state63 : begin
            ap_NS_fsm = ap_ST_fsm_state64;
        end
        ap_ST_fsm_state64 : begin
            ap_NS_fsm = ap_ST_fsm_state65;
        end
        ap_ST_fsm_state65 : begin
            ap_NS_fsm = ap_ST_fsm_state66;
        end
        ap_ST_fsm_state66 : begin
            ap_NS_fsm = ap_ST_fsm_state67;
        end
        ap_ST_fsm_state67 : begin
            ap_NS_fsm = ap_ST_fsm_state68;
        end
        ap_ST_fsm_state68 : begin
            ap_NS_fsm = ap_ST_fsm_state69;
        end
        ap_ST_fsm_state69 : begin
            ap_NS_fsm = ap_ST_fsm_state70;
        end
        ap_ST_fsm_state70 : begin
            ap_NS_fsm = ap_ST_fsm_state71;
        end
        ap_ST_fsm_state71 : begin
            ap_NS_fsm = ap_ST_fsm_state72;
        end
        ap_ST_fsm_state72 : begin
            ap_NS_fsm = ap_ST_fsm_state73;
        end
        ap_ST_fsm_state73 : begin
            ap_NS_fsm = ap_ST_fsm_state74;
        end
        ap_ST_fsm_state74 : begin
            ap_NS_fsm = ap_ST_fsm_state75;
        end
        ap_ST_fsm_state75 : begin
            ap_NS_fsm = ap_ST_fsm_state76;
        end
        ap_ST_fsm_state76 : begin
            ap_NS_fsm = ap_ST_fsm_state77;
        end
        ap_ST_fsm_state77 : begin
            ap_NS_fsm = ap_ST_fsm_state78;
        end
        ap_ST_fsm_state78 : begin
            ap_NS_fsm = ap_ST_fsm_state79;
        end
        ap_ST_fsm_state79 : begin
            ap_NS_fsm = ap_ST_fsm_state80;
        end
        ap_ST_fsm_state80 : begin
            ap_NS_fsm = ap_ST_fsm_state81;
        end
        ap_ST_fsm_state81 : begin
            ap_NS_fsm = ap_ST_fsm_state82;
        end
        ap_ST_fsm_state82 : begin
            ap_NS_fsm = ap_ST_fsm_state83;
        end
        ap_ST_fsm_state83 : begin
            ap_NS_fsm = ap_ST_fsm_state84;
        end
        ap_ST_fsm_state84 : begin
            ap_NS_fsm = ap_ST_fsm_state85;
        end
        ap_ST_fsm_state85 : begin
            ap_NS_fsm = ap_ST_fsm_state86;
        end
        ap_ST_fsm_state86 : begin
            ap_NS_fsm = ap_ST_fsm_state87;
        end
        ap_ST_fsm_state87 : begin
            ap_NS_fsm = ap_ST_fsm_state88;
        end
        ap_ST_fsm_state88 : begin
            ap_NS_fsm = ap_ST_fsm_state89;
        end
        ap_ST_fsm_state89 : begin
            ap_NS_fsm = ap_ST_fsm_state90;
        end
        ap_ST_fsm_state90 : begin
            ap_NS_fsm = ap_ST_fsm_state91;
        end
        ap_ST_fsm_state91 : begin
            ap_NS_fsm = ap_ST_fsm_state92;
        end
        ap_ST_fsm_state92 : begin
            ap_NS_fsm = ap_ST_fsm_state93;
        end
        ap_ST_fsm_state93 : begin
            ap_NS_fsm = ap_ST_fsm_state94;
        end
        ap_ST_fsm_state94 : begin
            ap_NS_fsm = ap_ST_fsm_state95;
        end
        ap_ST_fsm_state95 : begin
            ap_NS_fsm = ap_ST_fsm_state96;
        end
        ap_ST_fsm_state96 : begin
            ap_NS_fsm = ap_ST_fsm_state97;
        end
        ap_ST_fsm_state97 : begin
            ap_NS_fsm = ap_ST_fsm_state98;
        end
        ap_ST_fsm_state98 : begin
            ap_NS_fsm = ap_ST_fsm_state99;
        end
        ap_ST_fsm_state99 : begin
            ap_NS_fsm = ap_ST_fsm_state100;
        end
        ap_ST_fsm_state100 : begin
            ap_NS_fsm = ap_ST_fsm_state101;
        end
        ap_ST_fsm_state101 : begin
            ap_NS_fsm = ap_ST_fsm_state102;
        end
        ap_ST_fsm_state102 : begin
            ap_NS_fsm = ap_ST_fsm_state103;
        end
        ap_ST_fsm_state103 : begin
            ap_NS_fsm = ap_ST_fsm_state104;
        end
        ap_ST_fsm_state104 : begin
            ap_NS_fsm = ap_ST_fsm_state105;
        end
        ap_ST_fsm_state105 : begin
            ap_NS_fsm = ap_ST_fsm_state106;
        end
        ap_ST_fsm_state106 : begin
            ap_NS_fsm = ap_ST_fsm_state107;
        end
        ap_ST_fsm_state107 : begin
            ap_NS_fsm = ap_ST_fsm_state108;
        end
        ap_ST_fsm_state108 : begin
            ap_NS_fsm = ap_ST_fsm_state109;
        end
        ap_ST_fsm_state109 : begin
            if (((1'b1 == ap_CS_fsm_state109) & (ss_full_n == 1'b1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state109;
            end
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign DESTINO_out_din = DESTINO_dout;

assign add_ln878_fu_177_p2 = (j_V_reg_101 + 31'd1);

assign ap_CS_fsm_pp0_stage0 = ap_CS_fsm[32'd2];

assign ap_CS_fsm_pp0_stage1 = ap_CS_fsm[32'd3];

assign ap_CS_fsm_pp0_stage2 = ap_CS_fsm[32'd4];

assign ap_CS_fsm_pp0_stage3 = ap_CS_fsm[32'd5];

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state106 = ap_CS_fsm[32'd98];

assign ap_CS_fsm_state107 = ap_CS_fsm[32'd99];

assign ap_CS_fsm_state108 = ap_CS_fsm[32'd100];

assign ap_CS_fsm_state109 = ap_CS_fsm[32'd101];

assign ap_CS_fsm_state14 = ap_CS_fsm[32'd6];

assign ap_CS_fsm_state15 = ap_CS_fsm[32'd7];

assign ap_CS_fsm_state16 = ap_CS_fsm[32'd8];

assign ap_CS_fsm_state17 = ap_CS_fsm[32'd9];

assign ap_CS_fsm_state18 = ap_CS_fsm[32'd10];

assign ap_CS_fsm_state19 = ap_CS_fsm[32'd11];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state20 = ap_CS_fsm[32'd12];

assign ap_CS_fsm_state40 = ap_CS_fsm[32'd32];

assign ap_CS_fsm_state41 = ap_CS_fsm[32'd33];

assign ap_CS_fsm_state47 = ap_CS_fsm[32'd39];

assign ap_CS_fsm_state48 = ap_CS_fsm[32'd40];

assign ap_block_pp0_stage0 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage0_11001 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage0_subdone = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage1 = ~(1'b1 == 1'b1);

always @ (*) begin
    ap_block_pp0_stage1_11001 = ((ap_enable_reg_pp0_iter0 == 1'b1) & (((1'b0 == aa_empty_n) & (icmp_ln878_1_reg_243 == 1'd1)) | ((icmp_ln878_1_reg_243 == 1'd1) & (bb1_empty_n == 1'b0))));
end

always @ (*) begin
    ap_block_pp0_stage1_subdone = ((ap_enable_reg_pp0_iter0 == 1'b1) & (((1'b0 == aa_empty_n) & (icmp_ln878_1_reg_243 == 1'd1)) | ((icmp_ln878_1_reg_243 == 1'd1) & (bb1_empty_n == 1'b0))));
end

assign ap_block_pp0_stage2 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage2_11001 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage2_subdone = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage3_11001 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage3_subdone = ~(1'b1 == 1'b1);

always @ (*) begin
    ap_block_state1 = ((1'b0 == DESTINO_out_full_n) | (1'b0 == ORIGEN_empty_n) | (1'b0 == DESTINO_empty_n) | (ap_done_reg == 1'b1) | (ap_start == 1'b0));
end

assign ap_block_state10_pp0_stage3_iter1 = ~(1'b1 == 1'b1);

assign ap_block_state11_pp0_stage0_iter2 = ~(1'b1 == 1'b1);

assign ap_block_state12_pp0_stage1_iter2 = ~(1'b1 == 1'b1);

assign ap_block_state13_pp0_stage2_iter2 = ~(1'b1 == 1'b1);

assign ap_block_state3_pp0_stage0_iter0 = ~(1'b1 == 1'b1);

always @ (*) begin
    ap_block_state4_pp0_stage1_iter0 = (((1'b0 == aa_empty_n) & (icmp_ln878_1_reg_243 == 1'd1)) | ((icmp_ln878_1_reg_243 == 1'd1) & (bb1_empty_n == 1'b0)));
end

assign ap_block_state5_pp0_stage2_iter0 = ~(1'b1 == 1'b1);

assign ap_block_state6_pp0_stage3_iter0 = ~(1'b1 == 1'b1);

assign ap_block_state7_pp0_stage0_iter1 = ~(1'b1 == 1'b1);

assign ap_block_state8_pp0_stage1_iter1 = ~(1'b1 == 1'b1);

assign ap_block_state9_pp0_stage2_iter1 = ~(1'b1 == 1'b1);

assign ap_enable_pp0 = (ap_idle_pp0 ^ 1'b1);

assign i_V_1_fu_192_p2 = (ap_phi_mux_i_V_phi_fu_128_p4 + 31'd1);

assign i_V_cast_fu_198_p1 = ap_phi_mux_i_V_phi_fu_128_p4;

assign icmp_ln878_1_fu_202_p2 = (($signed(i_V_cast_fu_198_p1) < $signed(ORIGEN_read_reg_224)) ? 1'b1 : 1'b0);

assign icmp_ln878_fu_187_p2 = (($signed(zext_ln24_fu_183_p1) < $signed(DESTINO_read_reg_219)) ? 1'b1 : 1'b0);

assign ss_din = temp2_reg_298;

assign tmp_1_fu_211_p1 = bb1_read_reg_252;

assign tmp_fu_207_p1 = aa_read_reg_247;

assign zext_ln24_fu_183_p1 = j_V_reg_101;

endmodule //MVM_opcion7_super_mejorada_layer1
