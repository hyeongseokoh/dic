//three_bit_counter

module three_bit_counter #(
    
)(
    output xreal [2:0] Q,

    input xreal EN,
    input xreal CK,
    input xreal VDD
);

xreal node0;

counter counter_0(.Q(Q[0]), .EN(node0), .CK(CK) .VDD(VDD));
counter counter_1(.Q(Q[1]), .EN(Q[0]), .CK(CK) .VDD(VDD));
counter counter_2(.Q(Q[2]), .EN(Q[1]), .CK(CK) .VDD(VDD));

TG_mux and_1(.SEL(EN), .D0(`ground), .D1(Q[2]), .VDD(VDD));

endmodule
