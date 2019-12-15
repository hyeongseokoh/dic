//TG mux


module TG_mux #(
    parameter real WP = 4,     // pmos size in lambdas
    parameter real WN = 4      // nmos size in lambdas
)(
    output xreal Y,
    
    input xreal D0,
    input xreal D1,
    input xreal SEL,
    input xreal VDD

);

parameter real Rp = 40e3 * 2 / WP;
parameter real Rn = 20e3 * 2 / WN;
parameter real Cin = 2e-15*(WP+WN)*0.0225;
parameter real Cout = 2e-15*(WP+WN)*0.0225;
parameter real C_jp=2e-15*(WP)*0.0225;
parameter real C_jn=2e-15*(WN)*0.0225;
parameter real C_gn=2e-15*(WN)*0.0225;
parameter real C_gp=2e-15*(WP)*0.0225;

xbit SEL_xb;

xreal_to_xbit_var   CONN_SEL(.in(SEL), .out(SEL_xb), .level1(VDD), .level0(`ground));

switch #(.R0(Rp), .R1(`INFINITY)) SW_D0_p (.ctrl(SEL_xb), .pos(D0), .neg(Y));
switch #(.R0(`INFINITY), .R1(Rn)) SW_sel_n (.ctrl(SEL_xb), .pos(Y), .neg(D1));

capacitor   #(.C(C_gn+C_gp))      C_SEL (.pos(SEL), .neg(`ground));
capacitor   #(.C(C_jp+0.5*C_gp))  C_D0 (.pos(D0), .neg(`ground));
capacitor   #(.C(C_jn+0.5*C_gn))  C_D1 (.pos(D1), .neg(`ground));
capacitor   #(.C(C_jn+C_gn+0.5*C_gn+0.5*C_gp))  C_Y (.pos(Y), .neg(`ground));

endmodule
