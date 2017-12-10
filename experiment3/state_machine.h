#ifndef FSM_H
#define FSM_H

#include <systemc.h>

// TODO
SC_MODULE(stateMachine)
{
public:
	sc_in<bool> clk;
	sc_in<char> input;
    SC_HAS_PROCESS(stateMachine);
    stateMachine(const sc_module_name &name) : sc_module(name)
	{
        state = Start;
		SC_METHOD(process);
		sensitive << clk.pos();
		dont_initialize();
	}
private:
	enum base {Start,G,GA,GAA,GAAG};
	base state;
    unsigned int pattern_pos = 0;
    unsigned int pattern_counter = 0;
	void process();
};
#endif // FSM_H


