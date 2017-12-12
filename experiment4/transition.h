#ifndef TRANSITION
#define TRANSITION
#include <systemc.h>
#include "place.h"
SC_MODULE(transition)
{
public:
    sc_port <placeInterface> in;
    sc_port <placeInterface> out;
    SC_HAS_PROCESS(transition);
    transition(const sc_module_name &name) : sc_module(name)
    {
        SC_METHOD(fire);
        dont_initialize();
    }

    void fire();
};

#endif // TRANSITION

