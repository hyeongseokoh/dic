//RCA 8input

module eightbitinput_RCA #(
    
)(
    output xreal [8:0] result,

    input xreal [7:0] A,
    input xreal [7:0] B,
    
    input xreal VDD
);

xreal node0;
xreal node1;
xreal node2;
xreal node3;
xreal node4;
xreal node5;
xreal node6;
xreal node7;
xreal node8;

xreal node0_b;
xreal node1_b;
xreal node2_b;
xreal node3_b;
xreal node4_b;
xreal node5_b;
xreal node6_b;
xreal node7_b;
xreal node8_b;

eight_transistor_full_adder bit_0(.Cout(node0), .Cout_b(node0_b), .Sout(result[0]), .A(A[0]), .B(B[0]), .Cin(`ground), .Cin_b(VDD), .VDD(VDD));
eight_transistor_full_adder bit_1(.Cout(node1), .Cout_b(node1_b), .Sout(result[1]), .A(A[1]), .B(B[1]), .Cin(node0), .Cin_b(node0_b), .VDD(VDD));
eight_transistor_full_adder bit_2(.Cout(node2), .Cout_b(node2_b), .Sout(result[2]), .A(A[2]), .B(B[2]), .Cin(node1), .Cin_b(node1_b), .VDD(VDD));
eight_transistor_full_adder bit_3(.Cout(node3), .Cout_b(node3_b), .Sout(result[3]), .A(A[3]), .B(B[3]), .Cin(node2), .Cin_b(node2_b), .VDD(VDD));
eight_transistor_full_adder bit_4(.Cout(node4), .Cout_b(node4_b), .Sout(result[4]), .A(A[4]), .B(B[4]), .Cin(node3), .Cin_b(node3_b), .VDD(VDD));
eight_transistor_full_adder bit_5(.Cout(node5), .Cout_b(node5_b), .Sout(result[5]), .A(A[5]), .B(B[5]), .Cin(node4), .Cin_b(node4_b), .VDD(VDD));
eight_transistor_full_adder bit_6(.Cout(node6), .Cout_b(node6_b), .Sout(result[6]), .A(A[6]), .B(B[6]), .Cin(node5), .Cin_b(node5_b), .VDD(VDD));
eight_transistor_full_adder bit_7(.Cout(node7), .Cout_b(node7_b), .Sout(result[7]), .A(A[7]), .B(B[7]), .Cin(node6), .Cin_b(node6_b), .VDD(VDD));
eight_transistor_full_adder bit_8(.Cout(node8), .Cout_b(node8_b), .Sout(result[8]), .A(A[7]), .B(B[7]), .Cin(node7), .Cin_b(node7_b), .VDD(VDD));

endmodule
