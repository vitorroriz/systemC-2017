#ifndef TRANSITION
#define TRANSITION
#include <systemc.h>
#include "place.h"

template<unsigned int N=1, unsigned int M=1, unsigned int L=0>
SC_MODULE(transition)
{
public:
    sc_port <placeInterface, N, SC_ALL_BOUND> in;
    sc_port <placeInterface, M, SC_ALL_BOUND> out;
    sc_port <placeInterface, L, SC_ZERO_OR_MORE_BOUND> inhibitors;
    SC_HAS_PROCESS(transition);
    transition(const sc_module_name &name) : sc_module(name)
    {
    }

    //void fire(unsigned int n=N,unsigned int m=M);
    void fire();
};

#endif // TRANSITION

