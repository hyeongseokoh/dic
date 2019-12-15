//eight_mux
//

module eight_mux #(
    
)(
    output xreal [10:0] OUT,

    input xreal [2:0] SEL,
    input xreal [7:0] D0,
    input xreal [7:0] D1,
    input xreal [7:0] D2,
    input xreal [7:0] D3,
    input xreal [7:0] D4,
    input xreal [7:0] D5,
    input xreal [7:0] D6,
    input xreal [7:0] D7,
    
    input xreal VDD
);

xreal node0;

counter counter_0(.Q(Q[0]), .EN(node0), .CK(CK) .VDD(VDD));
counter counter_1(.Q(Q[1]), .EN(Q[0]), .CK(CK) .VDD(VDD));
counter counter_2(.Q(Q[2]), .EN(Q[1]), .CK(CK) .VDD(VDD));

TG_mux and_1(.SEL(EN), .D0(`ground), .D1(Q[2]), .VDD(VDD));

endmodule
