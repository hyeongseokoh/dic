//ReLU using 8 2:1 mux

module ReLU #(

)(
   output xreal [7:0] result,

   input xreal [10:0] S,
   input xreal VDD
);

TG_mux bit_0(.Y(result[0]), .D1(`ground), .D0(S[2]), .SEL(S[10]), .VDD(VDD));
TG_mux bit_1(.Y(result[1]), .D1(`ground), .D0(S[3]), .SEL(S[10]), .VDD(VDD));
TG_mux bit_2(.Y(result[2]), .D1(`ground), .D0(S[4]), .SEL(S[10]), .VDD(VDD));
TG_mux bit_3(.Y(result[3]), .D1(`ground), .D0(S[5]), .SEL(S[10]), .VDD(VDD));
TG_mux bit_4(.Y(result[4]), .D1(`ground), .D0(S[6]), .SEL(S[10]), .VDD(VDD));
TG_mux bit_5(.Y(result[5]), .D1(`ground), .D0(S[7]), .SEL(S[10]), .VDD(VDD));
TG_mux bit_6(.Y(result[6]), .D1(`ground), .D0(S[8]), .SEL(S[10]), .VDD(VDD));
TG_mux bit_7(.Y(result[7]), .D1(`ground), .D0(S[9]), .SEL(S[10]), .VDD(VDD));


endmodule
