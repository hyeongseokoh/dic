// eight_transistor_full_adder

// a 1-bit CLRCL full adder module


module eight_transistor_full_adder #(
    parameter real WP = 4,     // pmos size in lambdas
    parameter real WN = 4     // nmos size in lambdas    
)(
    output xreal Cout,
    //Addition of Cout_b
    output xreal Cout_b,
    output xreal Sout,

    input xreal A,
    input xreal B,
    input xreal Cin,

    //Addition of Cin_b from full adder
    input xreal Cin_b,
    
    input xreal VDD
);
xreal node1;

inv_RC inv_cout(.Y(Cout_b), .A(Cout), .VDD(VDD));
TG_mux mux_1(.Y(node1), .D0(Cin_b), .D1(Cin), .SEL(A), .VDD(VDD));
TG_mux mux_2(.Y(Cout), .D0(B), .D1(A), .SEL(node1), .VDD(VDD));
TG_mux mux_3(.Y(Sout), .D0(Cout_b), .D1(B), .SEL(node1), .VDD(VDD));

endmodule
