// ==============================================================
// RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Version: 2020.2
// Copyright (C) Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

module MVM_opcion7_super_mejorada_producer3 (
        ap_clk,
        ap_rst,
        ap_start,
        start_full_n,
        ap_done,
        ap_continue,
        ap_idle,
        ap_ready,
        start_out,
        start_write,
        aa_din,
        aa_full_n,
        aa_write,
        bb1_din,
        bb1_full_n,
        bb1_write,
        m_axi_gmem_AWVALID,
        m_axi_gmem_AWREADY,
        m_axi_gmem_AWADDR,
        m_axi_gmem_AWID,
        m_axi_gmem_AWLEN,
        m_axi_gmem_AWSIZE,
        m_axi_gmem_AWBURST,
        m_axi_gmem_AWLOCK,
        m_axi_gmem_AWCACHE,
        m_axi_gmem_AWPROT,
        m_axi_gmem_AWQOS,
        m_axi_gmem_AWREGION,
        m_axi_gmem_AWUSER,
        m_axi_gmem_WVALID,
        m_axi_gmem_WREADY,
        m_axi_gmem_WDATA,
        m_axi_gmem_WSTRB,
        m_axi_gmem_WLAST,
        m_axi_gmem_WID,
        m_axi_gmem_WUSER,
        m_axi_gmem_ARVALID,
        m_axi_gmem_ARREADY,
        m_axi_gmem_ARADDR,
        m_axi_gmem_ARID,
        m_axi_gmem_ARLEN,
        m_axi_gmem_ARSIZE,
        m_axi_gmem_ARBURST,
        m_axi_gmem_ARLOCK,
        m_axi_gmem_ARCACHE,
        m_axi_gmem_ARPROT,
        m_axi_gmem_ARQOS,
        m_axi_gmem_ARREGION,
        m_axi_gmem_ARUSER,
        m_axi_gmem_RVALID,
        m_axi_gmem_RREADY,
        m_axi_gmem_RDATA,
        m_axi_gmem_RLAST,
        m_axi_gmem_RID,
        m_axi_gmem_RUSER,
        m_axi_gmem_RRESP,
        m_axi_gmem_BVALID,
        m_axi_gmem_BREADY,
        m_axi_gmem_BRESP,
        m_axi_gmem_BID,
        m_axi_gmem_BUSER,
        activacion,
        weight,
        DESTINO,
        ORIGEN,
        output_r,
        DESTINO_out_din,
        DESTINO_out_full_n,
        DESTINO_out_write,
        ORIGEN_out_din,
        ORIGEN_out_full_n,
        ORIGEN_out_write,
        output_out_din,
        output_out_full_n,
        output_out_write
);

parameter    ap_ST_fsm_state1 = 5'd1;
parameter    ap_ST_fsm_state2 = 5'd2;
parameter    ap_ST_fsm_pp0_stage0 = 5'd4;
parameter    ap_ST_fsm_pp0_stage1 = 5'd8;
parameter    ap_ST_fsm_state16 = 5'd16;

input   ap_clk;
input   ap_rst;
input   ap_start;
input   start_full_n;
output   ap_done;
input   ap_continue;
output   ap_idle;
output   ap_ready;
output   start_out;
output   start_write;
output  [31:0] aa_din;
input   aa_full_n;
output   aa_write;
output  [31:0] bb1_din;
input   bb1_full_n;
output   bb1_write;
output   m_axi_gmem_AWVALID;
input   m_axi_gmem_AWREADY;
output  [63:0] m_axi_gmem_AWADDR;
output  [0:0] m_axi_gmem_AWID;
output  [31:0] m_axi_gmem_AWLEN;
output  [2:0] m_axi_gmem_AWSIZE;
output  [1:0] m_axi_gmem_AWBURST;
output  [1:0] m_axi_gmem_AWLOCK;
output  [3:0] m_axi_gmem_AWCACHE;
output  [2:0] m_axi_gmem_AWPROT;
output  [3:0] m_axi_gmem_AWQOS;
output  [3:0] m_axi_gmem_AWREGION;
output  [0:0] m_axi_gmem_AWUSER;
output   m_axi_gmem_WVALID;
input   m_axi_gmem_WREADY;
output  [31:0] m_axi_gmem_WDATA;
output  [3:0] m_axi_gmem_WSTRB;
output   m_axi_gmem_WLAST;
output  [0:0] m_axi_gmem_WID;
output  [0:0] m_axi_gmem_WUSER;
output   m_axi_gmem_ARVALID;
input   m_axi_gmem_ARREADY;
output  [63:0] m_axi_gmem_ARADDR;
output  [0:0] m_axi_gmem_ARID;
output  [31:0] m_axi_gmem_ARLEN;
output  [2:0] m_axi_gmem_ARSIZE;
output  [1:0] m_axi_gmem_ARBURST;
output  [1:0] m_axi_gmem_ARLOCK;
output  [3:0] m_axi_gmem_ARCACHE;
output  [2:0] m_axi_gmem_ARPROT;
output  [3:0] m_axi_gmem_ARQOS;
output  [3:0] m_axi_gmem_ARREGION;
output  [0:0] m_axi_gmem_ARUSER;
input   m_axi_gmem_RVALID;
output   m_axi_gmem_RREADY;
input  [31:0] m_axi_gmem_RDATA;
input   m_axi_gmem_RLAST;
input  [0:0] m_axi_gmem_RID;
input  [0:0] m_axi_gmem_RUSER;
input  [1:0] m_axi_gmem_RRESP;
input   m_axi_gmem_BVALID;
output   m_axi_gmem_BREADY;
input  [1:0] m_axi_gmem_BRESP;
input  [0:0] m_axi_gmem_BID;
input  [0:0] m_axi_gmem_BUSER;
input  [63:0] activacion;
input  [63:0] weight;
input  [31:0] DESTINO;
input  [31:0] ORIGEN;
input  [63:0] output_r;
output  [31:0] DESTINO_out_din;
input   DESTINO_out_full_n;
output   DESTINO_out_write;
output  [31:0] ORIGEN_out_din;
input   ORIGEN_out_full_n;
output   ORIGEN_out_write;
output  [63:0] output_out_din;
input   output_out_full_n;
output   output_out_write;

reg ap_done;
reg ap_idle;
reg start_write;
reg aa_write;
reg bb1_write;
reg m_axi_gmem_ARVALID;
reg[63:0] m_axi_gmem_ARADDR;
reg m_axi_gmem_RREADY;
reg DESTINO_out_write;
reg ORIGEN_out_write;
reg output_out_write;

reg    real_start;
reg    start_once_reg;
reg    ap_done_reg;
(* fsm_encoding = "none" *) reg   [4:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
reg    internal_ap_ready;
reg    aa_blk_n;
wire    ap_CS_fsm_pp0_stage0;
reg    ap_enable_reg_pp0_iter6;
wire    ap_block_pp0_stage0;
reg   [0:0] icmp_ln13_reg_394;
reg   [0:0] icmp_ln13_reg_394_pp0_iter5_reg;
reg    bb1_blk_n;
reg    gmem_blk_n_AR;
wire    ap_CS_fsm_pp0_stage1;
reg    ap_enable_reg_pp0_iter0;
wire    ap_block_pp0_stage1;
reg    gmem_blk_n_R;
reg    ap_enable_reg_pp0_iter4;
reg   [0:0] icmp_ln13_reg_394_pp0_iter3_reg;
reg    ap_enable_reg_pp0_iter2;
reg   [0:0] icmp_ln13_reg_394_pp0_iter1_reg;
reg    ap_enable_reg_pp0_iter5;
reg    DESTINO_out_blk_n;
reg    ORIGEN_out_blk_n;
reg    output_out_blk_n;
reg   [63:0] indvar_flatten_reg_178;
reg   [31:0] j_reg_189;
reg   [31:0] i_reg_200;
wire    ap_CS_fsm_state2;
wire  signed [62:0] sext_ln13_fu_235_p1;
reg  signed [62:0] sext_ln13_reg_374;
wire   [61:0] ORIGEN_cast_i_i_fu_239_p1;
reg   [61:0] ORIGEN_cast_i_i_reg_379;
wire   [63:0] grp_fu_219_p2;
reg   [63:0] mul_ln11_reg_384;
wire   [63:0] add_ln13_fu_242_p2;
reg   [63:0] add_ln13_reg_389;
wire    ap_block_state3_pp0_stage0_iter0;
wire    ap_block_state5_pp0_stage0_iter1;
wire    ap_block_state7_pp0_stage0_iter2;
reg    ap_block_state7_io;
wire    ap_block_state9_pp0_stage0_iter3;
reg    ap_block_state11_pp0_stage0_iter4;
wire    ap_block_state13_pp0_stage0_iter5;
reg    ap_block_state15_pp0_stage0_iter6;
reg    ap_block_pp0_stage0_11001;
wire   [0:0] icmp_ln13_fu_248_p2;
reg   [0:0] icmp_ln13_reg_394_pp0_iter2_reg;
reg   [0:0] icmp_ln13_reg_394_pp0_iter4_reg;
wire   [31:0] select_ln13_fu_258_p3;
reg   [31:0] select_ln13_reg_398;
wire   [31:0] select_ln13_1_fu_272_p3;
reg   [31:0] select_ln13_1_reg_403;
wire   [62:0] i_cast_i_i_fu_280_p1;
reg   [62:0] i_cast_i_i_reg_409;
reg   [62:0] i_cast_i_i_reg_409_pp0_iter1_reg;
reg   [63:0] gmem_addr_reg_414;
wire    ap_block_state4_pp0_stage1_iter0;
reg    ap_block_state4_io;
wire    ap_block_state6_pp0_stage1_iter1;
wire    ap_block_state8_pp0_stage1_iter2;
wire    ap_block_state10_pp0_stage1_iter3;
wire    ap_block_state12_pp0_stage1_iter4;
reg    ap_block_state14_pp0_stage1_iter5;
reg    ap_block_pp0_stage1_11001;
wire   [31:0] add_ln15_fu_307_p2;
reg   [31:0] add_ln15_reg_425;
wire   [61:0] grp_fu_302_p2;
reg   [61:0] mul_ln13_reg_430;
reg   [63:0] gmem_addr_1_reg_435;
reg   [31:0] gmem_addr_read_reg_441;
reg   [31:0] gmem_addr_read_reg_441_pp0_iter5_reg;
reg   [31:0] gmem_addr_1_read_reg_446;
reg    ap_block_pp0_stage0_subdone;
reg    ap_condition_pp0_exit_iter0_state3;
reg    ap_enable_reg_pp0_iter1;
reg    ap_block_pp0_stage1_subdone;
reg    ap_enable_reg_pp0_iter3;
reg   [63:0] ap_phi_mux_indvar_flatten_phi_fu_182_p4;
reg   [31:0] ap_phi_mux_j_phi_fu_193_p4;
reg   [31:0] ap_phi_mux_i_phi_fu_204_p4;
wire  signed [63:0] sext_ln174_fu_289_p1;
wire  signed [63:0] sext_ln174_1_fu_343_p1;
reg    ap_block_state1;
reg    ap_block_pp0_stage0_01001;
wire   [31:0] grp_fu_219_p0;
wire   [31:0] grp_fu_219_p1;
wire   [61:0] trunc_ln_fu_225_p4;
wire   [0:0] icmp_ln15_fu_253_p2;
wire   [31:0] add_ln13_2_fu_266_p2;
wire   [62:0] add_ln174_fu_284_p2;
wire   [31:0] grp_fu_302_p0;
wire   [31:0] grp_fu_302_p1;
wire   [63:0] sext_ln15_mid2_v_v_v_v_fu_312_p3;
wire   [63:0] add_ln13_1_fu_319_p2;
wire   [61:0] sext_ln15_mid2_v_fu_324_p4;
wire  signed [62:0] sext_ln13_1_fu_334_p1;
wire   [62:0] add_ln174_1_fu_338_p2;
reg    grp_fu_219_ce;
reg    grp_fu_302_ce;
wire    ap_CS_fsm_state16;
reg   [4:0] ap_NS_fsm;
reg    ap_idle_pp0;
wire    ap_enable_pp0;
wire   [63:0] grp_fu_219_p00;
wire   [63:0] grp_fu_219_p10;
wire   [61:0] grp_fu_302_p10;
wire    ap_ce_reg;

// power-on initialization
initial begin
#0 start_once_reg = 1'b0;
#0 ap_done_reg = 1'b0;
#0 ap_CS_fsm = 5'd1;
#0 ap_enable_reg_pp0_iter6 = 1'b0;
#0 ap_enable_reg_pp0_iter0 = 1'b0;
#0 ap_enable_reg_pp0_iter4 = 1'b0;
#0 ap_enable_reg_pp0_iter2 = 1'b0;
#0 ap_enable_reg_pp0_iter5 = 1'b0;
#0 ap_enable_reg_pp0_iter1 = 1'b0;
#0 ap_enable_reg_pp0_iter3 = 1'b0;
end

MVM_opcion7_super_mejorada_mul_32ns_32ns_64_2_1 #(
    .ID( 1 ),
    .NUM_STAGE( 2 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 32 ),
    .dout_WIDTH( 64 ))
mul_32ns_32ns_64_2_1_U1(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(grp_fu_219_p0),
    .din1(grp_fu_219_p1),
    .ce(grp_fu_219_ce),
    .dout(grp_fu_219_p2)
);

MVM_opcion7_super_mejorada_mul_32ns_32ns_62_2_1 #(
    .ID( 1 ),
    .NUM_STAGE( 2 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 32 ),
    .dout_WIDTH( 62 ))
mul_32ns_32ns_62_2_1_U2(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(grp_fu_302_p0),
    .din1(grp_fu_302_p1),
    .ce(grp_fu_302_ce),
    .dout(grp_fu_302_p2)
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
        end else if ((1'b1 == ap_CS_fsm_state16)) begin
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
        end else if ((1'b1 == ap_CS_fsm_state2)) begin
            ap_enable_reg_pp0_iter0 <= 1'b1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter1 <= 1'b0;
    end else begin
        if (((1'b1 == ap_CS_fsm_pp0_stage1) & (1'b0 == ap_block_pp0_stage1_subdone))) begin
            ap_enable_reg_pp0_iter1 <= ap_enable_reg_pp0_iter0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter2 <= 1'b0;
    end else begin
        if (((1'b1 == ap_CS_fsm_pp0_stage1) & (1'b0 == ap_block_pp0_stage1_subdone))) begin
            ap_enable_reg_pp0_iter2 <= ap_enable_reg_pp0_iter1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter3 <= 1'b0;
    end else begin
        if (((1'b1 == ap_CS_fsm_pp0_stage1) & (1'b0 == ap_block_pp0_stage1_subdone))) begin
            ap_enable_reg_pp0_iter3 <= ap_enable_reg_pp0_iter2;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter4 <= 1'b0;
    end else begin
        if (((1'b1 == ap_CS_fsm_pp0_stage1) & (1'b0 == ap_block_pp0_stage1_subdone))) begin
            ap_enable_reg_pp0_iter4 <= ap_enable_reg_pp0_iter3;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter5 <= 1'b0;
    end else begin
        if (((1'b1 == ap_CS_fsm_pp0_stage1) & (1'b0 == ap_block_pp0_stage1_subdone))) begin
            ap_enable_reg_pp0_iter5 <= ap_enable_reg_pp0_iter4;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter6 <= 1'b0;
    end else begin
        if ((((1'b1 == ap_CS_fsm_pp0_stage1) & (1'b0 == ap_block_pp0_stage1_subdone)) | ((1'b1 == ap_CS_fsm_pp0_stage0) & (ap_enable_reg_pp0_iter5 == 1'b0) & (1'b0 == ap_block_pp0_stage0_subdone)))) begin
            ap_enable_reg_pp0_iter6 <= ap_enable_reg_pp0_iter5;
        end else if ((1'b1 == ap_CS_fsm_state2)) begin
            ap_enable_reg_pp0_iter6 <= 1'b0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        start_once_reg <= 1'b0;
    end else begin
        if (((internal_ap_ready == 1'b0) & (real_start == 1'b1))) begin
            start_once_reg <= 1'b1;
        end else if ((internal_ap_ready == 1'b1)) begin
            start_once_reg <= 1'b0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (icmp_ln13_reg_394 == 1'd0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        i_reg_200 <= add_ln15_reg_425;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        i_reg_200 <= 32'd0;
    end
end

always @ (posedge ap_clk) begin
    if (((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (icmp_ln13_reg_394 == 1'd0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        indvar_flatten_reg_178 <= add_ln13_reg_389;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        indvar_flatten_reg_178 <= 64'd0;
    end
end

always @ (posedge ap_clk) begin
    if (((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (icmp_ln13_reg_394 == 1'd0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        j_reg_189 <= select_ln13_1_reg_403;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        j_reg_189 <= 32'd0;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        ORIGEN_cast_i_i_reg_379[31 : 0] <= ORIGEN_cast_i_i_fu_239_p1[31 : 0];
        mul_ln11_reg_384 <= grp_fu_219_p2;
        sext_ln13_reg_374 <= sext_ln13_fu_235_p1;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage0) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        add_ln13_reg_389 <= add_ln13_fu_242_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage1) & (ap_enable_reg_pp0_iter0 == 1'b1) & (icmp_ln13_reg_394 == 1'd0) & (1'b0 == ap_block_pp0_stage1_11001))) begin
        add_ln15_reg_425 <= add_ln15_fu_307_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage1) & (icmp_ln13_reg_394_pp0_iter5_reg == 1'd0) & (1'b0 == ap_block_pp0_stage1_11001))) begin
        gmem_addr_1_read_reg_446 <= m_axi_gmem_RDATA;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage1) & (icmp_ln13_reg_394_pp0_iter1_reg == 1'd0) & (1'b0 == ap_block_pp0_stage1_11001))) begin
        gmem_addr_1_reg_435 <= sext_ln174_1_fu_343_p1;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage0) & (icmp_ln13_reg_394_pp0_iter3_reg == 1'd0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        gmem_addr_read_reg_441 <= m_axi_gmem_RDATA;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        gmem_addr_read_reg_441_pp0_iter5_reg <= gmem_addr_read_reg_441;
        i_cast_i_i_reg_409_pp0_iter1_reg[31 : 0] <= i_cast_i_i_reg_409[31 : 0];
        icmp_ln13_reg_394 <= icmp_ln13_fu_248_p2;
        icmp_ln13_reg_394_pp0_iter1_reg <= icmp_ln13_reg_394;
        icmp_ln13_reg_394_pp0_iter2_reg <= icmp_ln13_reg_394_pp0_iter1_reg;
        icmp_ln13_reg_394_pp0_iter3_reg <= icmp_ln13_reg_394_pp0_iter2_reg;
        icmp_ln13_reg_394_pp0_iter4_reg <= icmp_ln13_reg_394_pp0_iter3_reg;
        icmp_ln13_reg_394_pp0_iter5_reg <= icmp_ln13_reg_394_pp0_iter4_reg;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln13_fu_248_p2 == 1'd0) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        gmem_addr_reg_414 <= sext_ln174_fu_289_p1;
        i_cast_i_i_reg_409[31 : 0] <= i_cast_i_i_fu_280_p1[31 : 0];
        select_ln13_reg_398 <= select_ln13_fu_258_p3;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage0) & (icmp_ln13_reg_394 == 1'd0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        mul_ln13_reg_430 <= grp_fu_302_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln13_fu_248_p2 == 1'd0) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        select_ln13_1_reg_403 <= select_ln13_1_fu_272_p3;
    end
end

always @ (*) begin
    if ((~((ap_done_reg == 1'b1) | (real_start == 1'b0)) & (1'b1 == ap_CS_fsm_state1))) begin
        DESTINO_out_blk_n = DESTINO_out_full_n;
    end else begin
        DESTINO_out_blk_n = 1'b1;
    end
end

always @ (*) begin
    if ((~((1'b0 == ORIGEN_out_full_n) | (1'b0 == DESTINO_out_full_n) | (ap_done_reg == 1'b1) | (output_out_full_n == 1'b0) | (real_start == 1'b0)) & (1'b1 == ap_CS_fsm_state1))) begin
        DESTINO_out_write = 1'b1;
    end else begin
        DESTINO_out_write = 1'b0;
    end
end

always @ (*) begin
    if ((~((ap_done_reg == 1'b1) | (real_start == 1'b0)) & (1'b1 == ap_CS_fsm_state1))) begin
        ORIGEN_out_blk_n = ORIGEN_out_full_n;
    end else begin
        ORIGEN_out_blk_n = 1'b1;
    end
end

always @ (*) begin
    if ((~((1'b0 == ORIGEN_out_full_n) | (1'b0 == DESTINO_out_full_n) | (ap_done_reg == 1'b1) | (output_out_full_n == 1'b0) | (real_start == 1'b0)) & (1'b1 == ap_CS_fsm_state1))) begin
        ORIGEN_out_write = 1'b1;
    end else begin
        ORIGEN_out_write = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage0) & (icmp_ln13_reg_394_pp0_iter5_reg == 1'd0) & (1'b0 == ap_block_pp0_stage0) & (ap_enable_reg_pp0_iter6 == 1'b1))) begin
        aa_blk_n = aa_full_n;
    end else begin
        aa_blk_n = 1'b1;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage0) & (icmp_ln13_reg_394_pp0_iter5_reg == 1'd0) & (1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter6 == 1'b1))) begin
        aa_write = 1'b1;
    end else begin
        aa_write = 1'b0;
    end
end

always @ (*) begin
    if ((icmp_ln13_fu_248_p2 == 1'd1)) begin
        ap_condition_pp0_exit_iter0_state3 = 1'b1;
    end else begin
        ap_condition_pp0_exit_iter0_state3 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state16)) begin
        ap_done = 1'b1;
    end else begin
        ap_done = ap_done_reg;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state1) & (real_start == 1'b0))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter3 == 1'b0) & (ap_enable_reg_pp0_iter1 == 1'b0) & (ap_enable_reg_pp0_iter5 == 1'b0) & (ap_enable_reg_pp0_iter2 == 1'b0) & (ap_enable_reg_pp0_iter4 == 1'b0) & (ap_enable_reg_pp0_iter0 == 1'b0) & (ap_enable_reg_pp0_iter6 == 1'b0))) begin
        ap_idle_pp0 = 1'b1;
    end else begin
        ap_idle_pp0 = 1'b0;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (icmp_ln13_reg_394 == 1'd0) & (1'b0 == ap_block_pp0_stage0))) begin
        ap_phi_mux_i_phi_fu_204_p4 = add_ln15_reg_425;
    end else begin
        ap_phi_mux_i_phi_fu_204_p4 = i_reg_200;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (icmp_ln13_reg_394 == 1'd0) & (1'b0 == ap_block_pp0_stage0))) begin
        ap_phi_mux_indvar_flatten_phi_fu_182_p4 = add_ln13_reg_389;
    end else begin
        ap_phi_mux_indvar_flatten_phi_fu_182_p4 = indvar_flatten_reg_178;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (icmp_ln13_reg_394 == 1'd0) & (1'b0 == ap_block_pp0_stage0))) begin
        ap_phi_mux_j_phi_fu_193_p4 = select_ln13_1_reg_403;
    end else begin
        ap_phi_mux_j_phi_fu_193_p4 = j_reg_189;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage0) & (icmp_ln13_reg_394_pp0_iter5_reg == 1'd0) & (1'b0 == ap_block_pp0_stage0) & (ap_enable_reg_pp0_iter6 == 1'b1))) begin
        bb1_blk_n = bb1_full_n;
    end else begin
        bb1_blk_n = 1'b1;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage0) & (icmp_ln13_reg_394_pp0_iter5_reg == 1'd0) & (1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter6 == 1'b1))) begin
        bb1_write = 1'b1;
    end else begin
        bb1_write = 1'b0;
    end
end

always @ (*) begin
    if ((((1'b1 == ap_CS_fsm_pp0_stage1) & (ap_enable_reg_pp0_iter0 == 1'b1) & (icmp_ln13_reg_394 == 1'd0) & (1'b0 == ap_block_pp0_stage1)) | ((1'b1 == ap_CS_fsm_pp0_stage0) & (icmp_ln13_reg_394_pp0_iter1_reg == 1'd0) & (ap_enable_reg_pp0_iter2 == 1'b1) & (1'b0 == ap_block_pp0_stage0)))) begin
        gmem_blk_n_AR = m_axi_gmem_ARREADY;
    end else begin
        gmem_blk_n_AR = 1'b1;
    end
end

always @ (*) begin
    if ((((1'b1 == ap_CS_fsm_pp0_stage1) & (ap_enable_reg_pp0_iter5 == 1'b1) & (icmp_ln13_reg_394_pp0_iter5_reg == 1'd0) & (1'b0 == ap_block_pp0_stage1)) | ((1'b1 == ap_CS_fsm_pp0_stage0) & (icmp_ln13_reg_394_pp0_iter3_reg == 1'd0) & (ap_enable_reg_pp0_iter4 == 1'b1) & (1'b0 == ap_block_pp0_stage0)))) begin
        gmem_blk_n_R = m_axi_gmem_RVALID;
    end else begin
        gmem_blk_n_R = 1'b1;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state2) | (~((1'b0 == ORIGEN_out_full_n) | (1'b0 == DESTINO_out_full_n) | (ap_done_reg == 1'b1) | (output_out_full_n == 1'b0) | (real_start == 1'b0)) & (1'b1 == ap_CS_fsm_state1)))) begin
        grp_fu_219_ce = 1'b1;
    end else begin
        grp_fu_219_ce = 1'b0;
    end
end

always @ (*) begin
    if ((((1'b1 == ap_CS_fsm_pp0_stage1) & (1'b0 == ap_block_pp0_stage1_11001)) | ((1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001)))) begin
        grp_fu_302_ce = 1'b1;
    end else begin
        grp_fu_302_ce = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state16)) begin
        internal_ap_ready = 1'b1;
    end else begin
        internal_ap_ready = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage0) & (icmp_ln13_reg_394_pp0_iter1_reg == 1'd0) & (ap_enable_reg_pp0_iter2 == 1'b1) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        m_axi_gmem_ARADDR = gmem_addr_1_reg_435;
    end else if (((1'b1 == ap_CS_fsm_pp0_stage1) & (ap_enable_reg_pp0_iter0 == 1'b1) & (icmp_ln13_reg_394 == 1'd0) & (1'b0 == ap_block_pp0_stage1_11001))) begin
        m_axi_gmem_ARADDR = gmem_addr_reg_414;
    end else begin
        m_axi_gmem_ARADDR = 'bx;
    end
end

always @ (*) begin
    if ((((1'b1 == ap_CS_fsm_pp0_stage1) & (ap_enable_reg_pp0_iter0 == 1'b1) & (icmp_ln13_reg_394 == 1'd0) & (1'b0 == ap_block_pp0_stage1_11001)) | ((1'b1 == ap_CS_fsm_pp0_stage0) & (icmp_ln13_reg_394_pp0_iter1_reg == 1'd0) & (ap_enable_reg_pp0_iter2 == 1'b1) & (1'b0 == ap_block_pp0_stage0_11001)))) begin
        m_axi_gmem_ARVALID = 1'b1;
    end else begin
        m_axi_gmem_ARVALID = 1'b0;
    end
end

always @ (*) begin
    if ((((1'b1 == ap_CS_fsm_pp0_stage1) & (ap_enable_reg_pp0_iter5 == 1'b1) & (icmp_ln13_reg_394_pp0_iter5_reg == 1'd0) & (1'b0 == ap_block_pp0_stage1_11001)) | ((1'b1 == ap_CS_fsm_pp0_stage0) & (icmp_ln13_reg_394_pp0_iter3_reg == 1'd0) & (ap_enable_reg_pp0_iter4 == 1'b1) & (1'b0 == ap_block_pp0_stage0_11001)))) begin
        m_axi_gmem_RREADY = 1'b1;
    end else begin
        m_axi_gmem_RREADY = 1'b0;
    end
end

always @ (*) begin
    if ((~((ap_done_reg == 1'b1) | (real_start == 1'b0)) & (1'b1 == ap_CS_fsm_state1))) begin
        output_out_blk_n = output_out_full_n;
    end else begin
        output_out_blk_n = 1'b1;
    end
end

always @ (*) begin
    if ((~((1'b0 == ORIGEN_out_full_n) | (1'b0 == DESTINO_out_full_n) | (ap_done_reg == 1'b1) | (output_out_full_n == 1'b0) | (real_start == 1'b0)) & (1'b1 == ap_CS_fsm_state1))) begin
        output_out_write = 1'b1;
    end else begin
        output_out_write = 1'b0;
    end
end

always @ (*) begin
    if (((start_once_reg == 1'b0) & (start_full_n == 1'b0))) begin
        real_start = 1'b0;
    end else begin
        real_start = ap_start;
    end
end

always @ (*) begin
    if (((start_once_reg == 1'b0) & (real_start == 1'b1))) begin
        start_write = 1'b1;
    end else begin
        start_write = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if ((~((1'b0 == ORIGEN_out_full_n) | (1'b0 == DESTINO_out_full_n) | (ap_done_reg == 1'b1) | (output_out_full_n == 1'b0) | (real_start == 1'b0)) & (1'b1 == ap_CS_fsm_state1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            ap_NS_fsm = ap_ST_fsm_pp0_stage0;
        end
        ap_ST_fsm_pp0_stage0 : begin
            if ((~((ap_enable_reg_pp0_iter1 == 1'b0) & (icmp_ln13_fu_248_p2 == 1'd1) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b0 == ap_block_pp0_stage0_subdone)) & ~((1'b1 == ap_CS_fsm_pp0_stage0) & (ap_enable_reg_pp0_iter5 == 1'b0) & (1'b0 == ap_block_pp0_stage0_subdone) & (ap_enable_reg_pp0_iter6 == 1'b1)) & (1'b0 == ap_block_pp0_stage0_subdone))) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage1;
            end else if ((((ap_enable_reg_pp0_iter1 == 1'b0) & (icmp_ln13_fu_248_p2 == 1'd1) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b0 == ap_block_pp0_stage0_subdone)) | ((1'b1 == ap_CS_fsm_pp0_stage0) & (ap_enable_reg_pp0_iter5 == 1'b0) & (1'b0 == ap_block_pp0_stage0_subdone) & (ap_enable_reg_pp0_iter6 == 1'b1)))) begin
                ap_NS_fsm = ap_ST_fsm_state16;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end
        end
        ap_ST_fsm_pp0_stage1 : begin
            if ((1'b0 == ap_block_pp0_stage1_subdone)) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage1;
            end
        end
        ap_ST_fsm_state16 : begin
            ap_NS_fsm = ap_ST_fsm_state1;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign DESTINO_out_din = DESTINO;

assign ORIGEN_cast_i_i_fu_239_p1 = ORIGEN;

assign ORIGEN_out_din = ORIGEN;

assign aa_din = gmem_addr_read_reg_441_pp0_iter5_reg;

assign add_ln13_1_fu_319_p2 = (sext_ln15_mid2_v_v_v_v_fu_312_p3 + weight);

assign add_ln13_2_fu_266_p2 = (ap_phi_mux_j_phi_fu_193_p4 + 32'd1);

assign add_ln13_fu_242_p2 = (ap_phi_mux_indvar_flatten_phi_fu_182_p4 + 64'd1);

assign add_ln15_fu_307_p2 = (select_ln13_reg_398 + 32'd1);

assign add_ln174_1_fu_338_p2 = ($signed(sext_ln13_1_fu_334_p1) + $signed(i_cast_i_i_reg_409_pp0_iter1_reg));

assign add_ln174_fu_284_p2 = ($signed(sext_ln13_reg_374) + $signed(i_cast_i_i_fu_280_p1));

assign ap_CS_fsm_pp0_stage0 = ap_CS_fsm[32'd2];

assign ap_CS_fsm_pp0_stage1 = ap_CS_fsm[32'd3];

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state16 = ap_CS_fsm[32'd4];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_block_pp0_stage0 = ~(1'b1 == 1'b1);

always @ (*) begin
    ap_block_pp0_stage0_01001 = (((m_axi_gmem_RVALID == 1'b0) & (icmp_ln13_reg_394_pp0_iter3_reg == 1'd0) & (ap_enable_reg_pp0_iter4 == 1'b1)) | ((ap_enable_reg_pp0_iter6 == 1'b1) & (((bb1_full_n == 1'b0) & (icmp_ln13_reg_394_pp0_iter5_reg == 1'd0)) | ((1'b0 == aa_full_n) & (icmp_ln13_reg_394_pp0_iter5_reg == 1'd0)))));
end

always @ (*) begin
    ap_block_pp0_stage0_11001 = (((m_axi_gmem_RVALID == 1'b0) & (icmp_ln13_reg_394_pp0_iter3_reg == 1'd0) & (ap_enable_reg_pp0_iter4 == 1'b1)) | ((1'b1 == ap_block_state7_io) & (ap_enable_reg_pp0_iter2 == 1'b1)) | ((ap_enable_reg_pp0_iter6 == 1'b1) & (((bb1_full_n == 1'b0) & (icmp_ln13_reg_394_pp0_iter5_reg == 1'd0)) | ((1'b0 == aa_full_n) & (icmp_ln13_reg_394_pp0_iter5_reg == 1'd0)))));
end

always @ (*) begin
    ap_block_pp0_stage0_subdone = (((m_axi_gmem_RVALID == 1'b0) & (icmp_ln13_reg_394_pp0_iter3_reg == 1'd0) & (ap_enable_reg_pp0_iter4 == 1'b1)) | ((1'b1 == ap_block_state7_io) & (ap_enable_reg_pp0_iter2 == 1'b1)) | ((ap_enable_reg_pp0_iter6 == 1'b1) & (((bb1_full_n == 1'b0) & (icmp_ln13_reg_394_pp0_iter5_reg == 1'd0)) | ((1'b0 == aa_full_n) & (icmp_ln13_reg_394_pp0_iter5_reg == 1'd0)))));
end

assign ap_block_pp0_stage1 = ~(1'b1 == 1'b1);

always @ (*) begin
    ap_block_pp0_stage1_11001 = (((1'b1 == ap_block_state4_io) & (ap_enable_reg_pp0_iter0 == 1'b1)) | ((m_axi_gmem_RVALID == 1'b0) & (ap_enable_reg_pp0_iter5 == 1'b1) & (icmp_ln13_reg_394_pp0_iter5_reg == 1'd0)));
end

always @ (*) begin
    ap_block_pp0_stage1_subdone = (((1'b1 == ap_block_state4_io) & (ap_enable_reg_pp0_iter0 == 1'b1)) | ((m_axi_gmem_RVALID == 1'b0) & (ap_enable_reg_pp0_iter5 == 1'b1) & (icmp_ln13_reg_394_pp0_iter5_reg == 1'd0)));
end

always @ (*) begin
    ap_block_state1 = ((1'b0 == ORIGEN_out_full_n) | (1'b0 == DESTINO_out_full_n) | (ap_done_reg == 1'b1) | (output_out_full_n == 1'b0) | (real_start == 1'b0));
end

assign ap_block_state10_pp0_stage1_iter3 = ~(1'b1 == 1'b1);

always @ (*) begin
    ap_block_state11_pp0_stage0_iter4 = ((m_axi_gmem_RVALID == 1'b0) & (icmp_ln13_reg_394_pp0_iter3_reg == 1'd0));
end

assign ap_block_state12_pp0_stage1_iter4 = ~(1'b1 == 1'b1);

assign ap_block_state13_pp0_stage0_iter5 = ~(1'b1 == 1'b1);

always @ (*) begin
    ap_block_state14_pp0_stage1_iter5 = ((m_axi_gmem_RVALID == 1'b0) & (icmp_ln13_reg_394_pp0_iter5_reg == 1'd0));
end

always @ (*) begin
    ap_block_state15_pp0_stage0_iter6 = (((bb1_full_n == 1'b0) & (icmp_ln13_reg_394_pp0_iter5_reg == 1'd0)) | ((1'b0 == aa_full_n) & (icmp_ln13_reg_394_pp0_iter5_reg == 1'd0)));
end

assign ap_block_state3_pp0_stage0_iter0 = ~(1'b1 == 1'b1);

always @ (*) begin
    ap_block_state4_io = ((m_axi_gmem_ARREADY == 1'b0) & (icmp_ln13_reg_394 == 1'd0));
end

assign ap_block_state4_pp0_stage1_iter0 = ~(1'b1 == 1'b1);

assign ap_block_state5_pp0_stage0_iter1 = ~(1'b1 == 1'b1);

assign ap_block_state6_pp0_stage1_iter1 = ~(1'b1 == 1'b1);

always @ (*) begin
    ap_block_state7_io = ((m_axi_gmem_ARREADY == 1'b0) & (icmp_ln13_reg_394_pp0_iter1_reg == 1'd0));
end

assign ap_block_state7_pp0_stage0_iter2 = ~(1'b1 == 1'b1);

assign ap_block_state8_pp0_stage1_iter2 = ~(1'b1 == 1'b1);

assign ap_block_state9_pp0_stage0_iter3 = ~(1'b1 == 1'b1);

assign ap_enable_pp0 = (ap_idle_pp0 ^ 1'b1);

assign ap_ready = internal_ap_ready;

assign bb1_din = gmem_addr_1_read_reg_446;

assign grp_fu_219_p0 = grp_fu_219_p00;

assign grp_fu_219_p00 = DESTINO;

assign grp_fu_219_p1 = grp_fu_219_p10;

assign grp_fu_219_p10 = ORIGEN;

assign grp_fu_302_p0 = ORIGEN_cast_i_i_reg_379;

assign grp_fu_302_p1 = grp_fu_302_p10;

assign grp_fu_302_p10 = select_ln13_1_reg_403;

assign i_cast_i_i_fu_280_p1 = select_ln13_fu_258_p3;

assign icmp_ln13_fu_248_p2 = ((ap_phi_mux_indvar_flatten_phi_fu_182_p4 == mul_ln11_reg_384) ? 1'b1 : 1'b0);

assign icmp_ln15_fu_253_p2 = ((ap_phi_mux_i_phi_fu_204_p4 == ORIGEN) ? 1'b1 : 1'b0);

assign m_axi_gmem_ARBURST = 2'd0;

assign m_axi_gmem_ARCACHE = 4'd0;

assign m_axi_gmem_ARID = 1'd0;

assign m_axi_gmem_ARLEN = 32'd1;

assign m_axi_gmem_ARLOCK = 2'd0;

assign m_axi_gmem_ARPROT = 3'd0;

assign m_axi_gmem_ARQOS = 4'd0;

assign m_axi_gmem_ARREGION = 4'd0;

assign m_axi_gmem_ARSIZE = 3'd0;

assign m_axi_gmem_ARUSER = 1'd0;

assign m_axi_gmem_AWADDR = 64'd0;

assign m_axi_gmem_AWBURST = 2'd0;

assign m_axi_gmem_AWCACHE = 4'd0;

assign m_axi_gmem_AWID = 1'd0;

assign m_axi_gmem_AWLEN = 32'd0;

assign m_axi_gmem_AWLOCK = 2'd0;

assign m_axi_gmem_AWPROT = 3'd0;

assign m_axi_gmem_AWQOS = 4'd0;

assign m_axi_gmem_AWREGION = 4'd0;

assign m_axi_gmem_AWSIZE = 3'd0;

assign m_axi_gmem_AWUSER = 1'd0;

assign m_axi_gmem_AWVALID = 1'b0;

assign m_axi_gmem_BREADY = 1'b0;

assign m_axi_gmem_WDATA = 32'd0;

assign m_axi_gmem_WID = 1'd0;

assign m_axi_gmem_WLAST = 1'b0;

assign m_axi_gmem_WSTRB = 4'd0;

assign m_axi_gmem_WUSER = 1'd0;

assign m_axi_gmem_WVALID = 1'b0;

assign output_out_din = output_r;

assign select_ln13_1_fu_272_p3 = ((icmp_ln15_fu_253_p2[0:0] == 1'b1) ? add_ln13_2_fu_266_p2 : ap_phi_mux_j_phi_fu_193_p4);

assign select_ln13_fu_258_p3 = ((icmp_ln15_fu_253_p2[0:0] == 1'b1) ? 32'd0 : ap_phi_mux_i_phi_fu_204_p4);

assign sext_ln13_1_fu_334_p1 = $signed(sext_ln15_mid2_v_fu_324_p4);

assign sext_ln13_fu_235_p1 = $signed(trunc_ln_fu_225_p4);

assign sext_ln15_mid2_v_fu_324_p4 = {{add_ln13_1_fu_319_p2[63:2]}};

assign sext_ln15_mid2_v_v_v_v_fu_312_p3 = {{mul_ln13_reg_430}, {2'd0}};

assign sext_ln174_1_fu_343_p1 = $signed(add_ln174_1_fu_338_p2);

assign sext_ln174_fu_289_p1 = $signed(add_ln174_fu_284_p2);

assign start_out = real_start;

assign trunc_ln_fu_225_p4 = {{activacion[63:2]}};

always @ (posedge ap_clk) begin
    ORIGEN_cast_i_i_reg_379[61:32] <= 30'b000000000000000000000000000000;
    i_cast_i_i_reg_409[62:32] <= 31'b0000000000000000000000000000000;
    i_cast_i_i_reg_409_pp0_iter1_reg[62:32] <= 31'b0000000000000000000000000000000;
end

endmodule //MVM_opcion7_super_mejorada_producer3
