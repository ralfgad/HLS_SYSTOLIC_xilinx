module accu_half_0002(
	input   clock,
	input   resetn,
	input    n,	
	input   [15:0]  x,
	output logic  [15:0]  r
);

logic signed [19:0] acumulador, datoa,datoa_reg, pre_salida;
logic n_reg;

Float2Fixed 
#(.FIXEDSIZE(20),
.FLOATSIZE(16),
.MANTISSABITS(10),
.EXPONENTBITS(5)
) 
float2fixA (
   .InFloat(x),
   .InRadixPoint(11),
   .OutFixed(datoa),
    .OutException(),
    .OutOverflow()

   );

  

always_ff @(posedge clock or negedge resetn) 
    begin
        if (!resetn)
        begin
            acumulador<='0;
            datoa_reg<='0;
            r<='0;
            n_reg<=1'b0;
            

        end
        else begin
            datoa_reg<=datoa;
            r<=pre_salida;
            n_reg<=n;
            if (n_reg)
                acumulador<=datoa_reg;
            else begin
                acumulador<=acumulador+datoa_reg;
            end
        end
    end
    


Fixed2Float #(.FIXEDSIZE(20),
 .FLOATSIZE(16),
.MANTISSABITS(10),
.EXPONENTBITS(5)
 )
 fix2float (
    .InFixed(acumulador),
    .InRadixPoint(11),
    .OutFloat(pre_salida)
    ); 	
endmodule