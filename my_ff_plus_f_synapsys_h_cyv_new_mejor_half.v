module my_ff_plus_f_synapsys_h_cyv_half (

	input   clock,
	input   resetn,
	input   ivalid, 
	input   iready,
	output  ovalid, 
	output  oready,
	input    control,	
	input   [15:0]  datainA,
	input   [15:0] datainB,
	output   [15:0]  dataout);
	
	
	

 // assign ovalid = 1'b1;
  assign oready = iready;
  // ivalid, iready, resetn are ignored
  
  reg [2:0] shifter ;
  reg [5:0] shifter_valid;
  wire empieza_acumular;
  wire enable_magico;
  wire [15:0] producto, producto_filtrado ;
  //assign datainC=control?32'h00000000: dataout;
  always @(posedge clock)
  begin
	shifter<={control,shifter[2:1]};
	shifter_valid<={ivalid,shifter_valid[5:1]};
   end
  assign empieza_acumular = shifter[0];
  assign ovalid = shifter_valid[0];
  assign enable_magico=shifter_valid[3]; //genial
  assign producto_filtrado=enable_magico?producto:16'h0000;

	product_half_0003 mult_inst ( //latencia 3
		.clk    (clock),    //    clk.clk
		.areset (!resetn), // areset.reset
		.en     (1'b1),     //     en.en
		.a      (datainA),      //      a.a
		.b      (datainB),      //      b.b
//		.c      (datainC),      //      c.c
		.q      (producto)       //      q.q
	);
     accu_half_0002  acc_int ( //latencia 3
	 	.clock    (clock),    //    clk.clk
		.resetn (resetn), // areset.reset
	//	.en     (1'b1),     //     en.en
		.x      (producto_filtrado),      //      a.a
		.n      (empieza_acumular),      //      b.b
        .r      (dataout)
	);
	 
	 
endmodule
