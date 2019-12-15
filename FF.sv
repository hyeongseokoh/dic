//FlipFlop


module FF #(
    parameter real WP = 4,     // pmos size in lambdas
    parameter real WN = 4      // nmos size in lambdas
)(
    output xreal Q,
    
    input xreal D,
    input xreal CK,
    input xreal VDD

);

parameter real Rp = 40e3 * 2 / WP;
parameter real Rn = 20e3 * 2 / WN;
parameter real C_jp=2e-15*(WP)*0.0225;
parameter real C_jn=2e-15*(WN)*0.0225;
parameter real C_gn=2e-15*(WN)*0.0225;
parameter real C_gp=2e-15*(WP)*0.0225;

xbit CK_xb;

xreal node0;
xreal node1;
xreal node2;
xreal node3;

xreal_to_xbit_var   CONN_SEL(.in(CK), .out(CK_xb), .level1(VDD), .level0(`ground));

switch #(.R0(Rp), .R1(`INFINITY)) SW_CK_p (.ctrl(CK_xb), .pos(node1), .neg(node3));
switch #(.R0(`INFINITY), .R1(Rn)) SW_CK_n (.ctrl(CK_xb), .pos(node0), .neg(node1));
inv_RC inv_1(.Y(node0), .A(D), .VDD(VDD));
inv_RC inv_2(.Y(node1), .A(node2), .VDD(VDD));
inv_RC inv_3(.Y(node2), .A(node1), .VDD(VDD));
inv_RC inv_4(.Y(Q), .A(node3), .VDD(VDD));


capacitor   #(.C(C_gn+C_gp))      C_CK (.pos(CK), .neg(`ground));
capacitor   #(.C(C_jn+0.5*C_gn))  C_node0 (.pos(node0), .neg(`ground));
capacitor   #(.C(C_jn+0.5*C_gn+C_jp+0.5*C_gp))  C_node1 (.pos(node1), .neg(`ground));
capacitor   #(.C(C_jp+0.5*C_gp))  C_node3 (.pos(node3), .neg(`ground));

endmodule

