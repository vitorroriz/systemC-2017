#include "systemc.h"
#include "stim.h"
#include "exor.h"
#include "mon.h"

int sc_main(int argc, char* argv[])
{
	sc_signal<bool> sigA, sigB, sigZ;

	stim Stim1("Stimulus");
	Stim1.A(sigA);
	Stim1.B(sigB);

	exor DUT("exor");
	DUT.A(sigA);
	DUT.B(sigB);
	DUT.Z(sigZ);

	Monitor mon("Monitor");
	mon.A(sigA);
	mon.B(sigB);
	mon.Z(sigZ);

/* Adding Waveform tracing */
	sc_trace_file* Tf;
	Tf = sc_create_vcd_trace_file("traces");
//	((vcd_trace_file*)Tf)->sc_set_vcd_time_unit(-9);

	sc_trace(Tf, sigA, "A");
	sc_trace(Tf, sigB, "B");
	sc_trace(Tf, sigZ, "Z");

	sc_start();  // run forever
	sc_close_vcd_trace_file(Tf);

	return 0;

}
