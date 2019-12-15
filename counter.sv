//counter


module counter #(
    parameter real WP = 4,     // pmos size in lambdas
    parameter real WN = 4      // nmos size in lambdas
)(
    output xreal Q,
    
    input xreal EN,
    input xreal CK,
    input xreal VDD

);

parameter real Rp = 40e3 * 2 / WP;
parameter real Rn = 20e3 * 2 / WN;
parameter real C_jp=2e-15*(WP)*0.0225;
parameter real C_jn=2e-15*(WN)*0.0225;
parameter real C_gn=2e-15*(WN)*0.0225;
parameter real C_gp=2e-15*(WP)*0.0225;

xreal node0;
xreal node1;


inv_RC inv_1(.Y(node0), .A(Q), .VDD(VDD));

TG_mux and_1(.SEL(EN), .D0(`ground), .D1(node0), .VDD(VDD) );

FF ff_1(.D(node1), .Q(Q), .CK(CK), .VDD(VDD));

endmodule

