#include <systemc.h>
#include "transition.h"
#include "transition.cpp"
#include "place.h"
#include "place.cpp"


// TOPLEVEL
SC_MODULE(toplevel)
{
    public:
    transition<1,1> ACT;
    transition<1,1> RD;
    transition<1,1> PRE;
    transition<1,1> WR;
    Place<1,1> IDLE, ACTIVE;
    SC_CTOR(toplevel) : ACT("ACT"), RD("RD"), PRE("PRE"), WR("WR"),
       IDLE(1), ACTIVE(0)
    {
        SC_THREAD(process);
        ACT.in.bind(IDLE);
        ACT.out.bind(ACTIVE);
        RD.in.bind(ACTIVE);
        RD.out.bind(ACTIVE);
        PRE.in.bind(ACTIVE);
        PRE.out.bind(IDLE);
        WR.in.bind(ACTIVE);
        WR.out.bind(ACTIVE);
    }
    void process() {
        while(true) {
            wait(10,SC_NS);
            ACT.fire();
            wait(10,SC_NS);
            ACT.fire();
            wait(10,SC_NS);
            RD.fire();
            wait(10,SC_NS);
            WR.fire();
            wait(10,SC_NS);
            PRE.fire();
            wait(10,SC_NS);
            ACT.fire();
            sc_stop();

        }
    }
};


int sc_main(int argc, char* argv[])
{
    // TODO

    toplevel* t = new toplevel("t");
    sc_start();

    return 0;
}
