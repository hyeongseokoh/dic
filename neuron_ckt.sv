/*----------------------------------------------------------------------
MODULE neuron_ckt.sv

= Purpose =
An circuit-implementation model for a digital neuron.

= Description =
An XMODEL model of a neuron that adds eight 8-bit inputs
and produces a rectified linear (ReLU) output.
----------------------------------------------------------------------*/

module neuron_ckt (
    output xreal [7:0] Q_xr,
    input xreal [7:0] D0_xr, D1_xr, D2_xr, D3_xr, D4_xr, D5_xr, D6_xr, D7_xr,
    input xreal CK1_xr, CK2_xr,
    input xreal VDD1, VDD2, VDD3, VDD4, VDD5, VDD6, VDD7, VDD8
);

xreal [8:0] i0, i1, i2, i3;
xreal [9:0] i4, i5;
xreal[10:0] i6;

xreal VDD_ten;
xreal is_zero;
xreal s10_inv;


eightbitinput_RCA a8_0(.A(D0_xr), .B(D1_xr), .result(i0), .VDD(VDD1));
eightbitinput_RCA a8_1(.A(D2_xr), .B(D3_xr), .result(i1), .VDD(VDD2));
eightbitinput_RCA a8_2(.A(D4_xr), .B(D5_xr), .result(i2), .VDD(VDD3));
eightbitinput_RCA a8_3(.A(D6_xr), .B(D7_xr), .result(i3), .VDD(VDD4));
ninebitinput_RCA a9_0(.A(i0), .B(i1), .result(i4), .VDD(VDD5));
ninebitinput_RCA a9_1(.A(i2), .B(i3), .result(i5), .VDD(VDD6));

//nand2_RC nand_1(.Y(VDD_ten), .A(i4[9]), .B(i5[9]), .VDD(VDD7));

//or2_inv1 orinv_1(.Y(is_zero), .A(S[10]), .B(VDD_ten), .VDD(VDD))

tenbitinput_RCA a10_0(.A(i4), .B(i5), .result(i6), .VDD(VDD7));


ReLU relu(.S(i6), .VDD(VDD8), .result(Q_xr));
// describe your digital neuron implementation using RC models here


endmodule

