/*----------------------------------------------------------------------
 TESTBENCH tb_neuron.sv

= Purpose =
A testbench for the digital neuron model.

= Description =
The testbench feeds a random data to the digital neuron and checks whether
its output is matched to that of a reference neuron model. 
----------------------------------------------------------------------*/

module tb_neuron;

//---- signal declarations
// convention: add '_xb' suffix for xbit signals and '_xr' suffix for xreal signals
wire CK1, CK2; 
xbit CK1_xb, CK2_xb;
xreal CK1_xr, CK2_xr;
xreal VDD, VDD1, VDD2, VDD3, VDD4, VDD5, VDD6, VDD7, VDD8;
reg [7:0] D0, D1, D2, D3, D4, D5, D6, D7;
xreal [7:0] D0_xr, D1_xr, D2_xr, D3_xr, D4_xr, D5_xr, D6_xr, D7_xr;
wire [7:0] Q, Q_ref;
xreal [7:0] Q_xr;

//---- parameter definitions
parameter real f_CK1 = 100e6;//100e6
parameter real f_CK2 = 1e9;
parameter real Rdrv = 5e3;
parameter real Cdrv = 1e-15;
parameter real Cload = 20e-15;

//---- clocks generation
// CK1: 100MHz, CK2: frequency of your choice (e.g. 1GHz)
clk_gen     #(.freq(f_CK1)) I_CK1 (.out(CK1_xb));
clk_gen     #(.freq(f_CK2)) I_CK2 (.out(CK2_xb));
xbit_to_bit #(.width(2)) CONN_CK (.in({CK1_xb, CK2_xb}), .out({CK1, CK2}));

//---- supply voltage generation
//vsource     #(.dc(1.0), .mode("dc")) I_VDD (.pos(VDD), .neg(`ground), .in(`ground));
vsource     #(.dc(1.0), .mode("dc")) I_VDD (.pos(VDD), .neg(`ground), .in(`ground));
vsource     #(.dc(1.0), .mode("dc")) I_VDD1 (.pos(VDD1), .neg(`ground), .in(`ground));
vsource     #(.dc(1.0), .mode("dc")) I_VDD2 (.pos(VDD2), .neg(`ground), .in(`ground));
vsource     #(.dc(1.0), .mode("dc")) I_VDD3 (.pos(VDD3), .neg(`ground), .in(`ground));
vsource     #(.dc(1.0), .mode("dc")) I_VDD4 (.pos(VDD4), .neg(`ground), .in(`ground));
vsource     #(.dc(1.0), .mode("dc")) I_VDD5 (.pos(VDD5), .neg(`ground), .in(`ground));
vsource     #(.dc(1.0), .mode("dc")) I_VDD6 (.pos(VDD6), .neg(`ground), .in(`ground));
vsource     #(.dc(1.0), .mode("dc")) I_VDD7 (.pos(VDD7), .neg(`ground), .in(`ground));
vsource     #(.dc(1.0), .mode("dc")) I_VDD8 (.pos(VDD8), .neg(`ground), .in(`ground));



//---- input data generation
always @(posedge CK1) begin
    D0 = $random;
    D1 = $random;
    D2 = $random;
    D3 = $random;
    D4 = $random;
    D5 = $random;
    D6 = $random;
    D7 = $random;
end

//---- reference model
neuron_ref I_REF (.D0, .D1, .D2, .D3, .D4, .D5, .D6, .D7, .Q(Q_ref));

//---- circuit model
bit_to_xreal_var #(.width(8), .Rout(Rdrv), .Cout(Cdrv)) CONN_D0 (.in(D0), .out(D0_xr), .level1(VDD), .level0(`ground));
bit_to_xreal_var #(.width(8), .Rout(Rdrv), .Cout(Cdrv)) CONN_D1 (.in(D1), .out(D1_xr), .level1(VDD), .level0(`ground));
bit_to_xreal_var #(.width(8), .Rout(Rdrv), .Cout(Cdrv)) CONN_D2 (.in(D2), .out(D2_xr), .level1(VDD), .level0(`ground));
bit_to_xreal_var #(.width(8), .Rout(Rdrv), .Cout(Cdrv)) CONN_D3 (.in(D3), .out(D3_xr), .level1(VDD), .level0(`ground));
bit_to_xreal_var #(.width(8), .Rout(Rdrv), .Cout(Cdrv)) CONN_D4 (.in(D4), .out(D4_xr), .level1(VDD), .level0(`ground));
bit_to_xreal_var #(.width(8), .Rout(Rdrv), .Cout(Cdrv)) CONN_D5 (.in(D5), .out(D5_xr), .level1(VDD), .level0(`ground));
bit_to_xreal_var #(.width(8), .Rout(Rdrv), .Cout(Cdrv)) CONN_D6 (.in(D6), .out(D6_xr), .level1(VDD), .level0(`ground));
bit_to_xreal_var #(.width(8), .Rout(Rdrv), .Cout(Cdrv)) CONN_D7 (.in(D7), .out(D7_xr), .level1(VDD), .level0(`ground));
bit_to_xreal_var #(.width(1), .Rout(Rdrv), .Cout(Cdrv)) CONN_CK1 (.in(CK1), .out(CK1_xr), .level1(VDD), .level0(`ground));
bit_to_xreal_var #(.width(1), .Rout(Rdrv), .Cout(Cdrv)) CONN_CK2 (.in(CK2), .out(CK2_xr), .level1(VDD), .level0(`ground));

neuron_ckt I_CKT (.D0_xr(D0_xr), .D1_xr(D1_xr), .D2_xr(D2_xr), .D3_xr(D3_xr), .D4_xr(D4_xr), .D5_xr(D5_xr), .D6_xr(D6_xr), .D7_xr(D7_xr), .Q_xr(Q_xr), .CK1_xr(CK1_xr), .CK2_xr(CK2_xr), .VDD1(VDD1), .VDD2(VDD2), .VDD3(VDD3), .VDD4(VDD4), .VDD5(VDD5), .VDD6(VDD6), .VDD7(VDD7), .VDD8(VDD8));

capacitor        #(.C(Cload)) C0[7:0] (.pos(Q_xr), .neg(`ground));
xreal_to_bit_var #(.width(8)) CONN_Q (.in(Q_xr), .out(Q), .level1(VDD), .level0(`ground));

//---- output check
int pass=0, fail=0;
int iteration=0;
always @(posedge CK1) begin
    $display("number of iteration: %d", iteration);
    iteration=iteration+1;
    if (Q == Q_ref) begin pass++;
	
    end
    else begin
        $display($time, ": ERROR detected: %b vs. %b", Q, Q_ref);
        fail++;
    end
end

final begin
    $display("NUMBER OF ERRORS: %d out of %d\n", fail, pass+fail);
end

//---- waveform recording
initial begin
    $xmodel_dumpfile("tb_neuron.fsdb");
    $xmodel_dumpvars();
    $xmodel_dumpvars(I_VDD1.I);
    $xmodel_dumpvars(I_VDD2.I);
    $xmodel_dumpvars(I_VDD3.I);
    $xmodel_dumpvars(I_VDD4.I);
    $xmodel_dumpvars(I_VDD5.I);
    $xmodel_dumpvars(I_VDD6.I);
    $xmodel_dumpvars(I_VDD7.I);
    $xmodel_dumpvars(I_VDD8.I);
  #810ns; $finish;
end
   xbit trig_t1, trig_t2;
   real Etotal1, Etotal2, Etotal3, Etotal4, Etotal5, Etotal6,Etotal7,Etotal8;
   trig_time #(.delay(10e-9)) TRIG_t1(.out(trig_t1));
   trig_time #(.delay(800e-9)) TRIG_t2(.out(trig_t2));
   meas_integ MEAS1(.in(I_VDD1.I), .out(Etotal1), .from(trig_t1), .to(trig_t2));
   meas_integ MEAS2(.in(I_VDD2.I), .out(Etotal2), .from(trig_t1), .to(trig_t2));
   meas_integ MEAS3(.in(I_VDD3.I), .out(Etotal3), .from(trig_t1), .to(trig_t2));
   meas_integ MEAS4(.in(I_VDD4.I), .out(Etotal4), .from(trig_t1), .to(trig_t2));
   meas_integ MEAS5(.in(I_VDD5.I), .out(Etotal5), .from(trig_t1), .to(trig_t2));
   meas_integ MEAS6(.in(I_VDD6.I), .out(Etotal6), .from(trig_t1), .to(trig_t2));
   meas_integ MEAS7(.in(I_VDD7.I), .out(Etotal7), .from(trig_t1), .to(trig_t2));
   meas_integ MEAS8(.in(I_VDD8.I), .out(Etotal8), .from(trig_t1), .to(trig_t2));

always @(Etotal1 or Etotal2 or Etotal3 or Etotal4 or Etotal5 or Etotal6 or Etotal7 or Etotal8) begin
   if($time>0) $display ("MEASURED POWER:", (Etotal1+Etotal2+Etotal3+Etotal4+Etotal5+Etotal6+Etotal7+Etotal8)/(800e-9));

end

endmodule

