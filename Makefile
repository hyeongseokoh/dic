# Makefile
TIMESCALE=10fs/10fs

tb_neuron_ref:
	xmodel tb_neuron_ref.sv neuron_ref.sv --top tb_neuron_ref --simtime 1us --timescale $(TIMESCALE)

tb_neuron:
	xmodel tb_neuron.sv neuron_ref.sv neuron_ckt.sv eightbitinput_RCA.sv ninebitinput_RCA.sv tenbitinput_RCA.sv ReLU.sv eight_transistor_full_adder.sv TG_mux.sv nand2_RC.sv inv_RC.sv --top tb_neuron --simtime 1us --timescale $(TIMESCALE)

tb_inv_delay:
	xmodel tb_inv_delay.sv inv_RC.sv --top tb_inv_delay --simtime 100ns --timescale $(TIMESCALE)

tb_full_adder:
	xmodel tb_full_adder.sv one_bit_full_adder.sv inv_RC.sv --top tb_full_adder --simtime 100ns --timescale $(TIMESCALE)

tb_six_trans_full_adder:
	xmodel tb_six_trans_full_adder.sv six_transistor_full_adder.sv --top tb_six_trans_full_adder --simtime 100ns --timescale $(TIMESCALE)

tb_RCA:
	xmodel tb_RCA.sv tenbitinput_RCA.sv one_bit_full_adder.sv inv_RC.sv --top tb_RCA --simtime 100ns --timescale $(TIMESCALE)

tb_ReLU:
	xmodel tb_ReLU.sv ReLU.sv two_to_1_mux_RC.sv inv_RC.sv --top tb_ReLU --simtime 50ns --timescale $(TIMESCALE)

tb_neuron_criticalpath:
	xmodel tb_neuron_criticalpath.sv neuron_ckt.sv eightbitinput_RCA.sv ninebitinput_RCA.sv tenbitinput_RCA.sv ReLU.sv one_bit_full_adder.sv two_to_1_mux_RC.sv inv_RC.sv --top tb_neuron_criticalpath --simtime 20ns --timescale $(TIMESCALE)

tb_Mux:
	xmodel tb_1bit_2to1mux.sv two_to_1_mux_RC.sv inv_RC.sv --top tb_1bit_2to1mux --simtime 50ns --timescale $(TIMESCALE)

clean:
	xmodel --clean --simulator all
