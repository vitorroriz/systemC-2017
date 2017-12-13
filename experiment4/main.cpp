#include <systemc.h>
#include "transition.h"
#include "transition.cpp"
#include "place.h"
#include "place.cpp"


// TOPLEVEL
SC_MODULE(subnet)
{
    public:
    transition<1,1,1> ACT;
    transition<1,1> RD;
    transition<1,1> PRE;
    transition<1,1> WR;
    Place<1,1>  ACTIVE;
    SC_CTOR(subnet) : ACT("ACT"), RD("RD"), PRE("PRE"), WR("WR"),
       ACTIVE(0)
    {
        ACT.out.bind(ACTIVE);
        ACT.inhibitors.bind(ACTIVE);
        RD.in.bind(ACTIVE);
        RD.out.bind(ACTIVE);
        PRE.in.bind(ACTIVE);
        WR.in.bind(ACTIVE);
        WR.out.bind(ACTIVE);
    }
};

SC_MODULE(toplevel)
{
    public:
    Place<1,1> IDLE;
    subnet s1, s2;

    SC_CTOR(toplevel) : IDLE(2), s1("s1"), s2("s2")
    {
        SC_THREAD(process);
        s1.ACT.in.bind(IDLE);
        s2.ACT.in.bind(IDLE);
        s1.PRE.out.bind(IDLE);
        s2.PRE.out.bind(IDLE);
    }
    void process() {
        while(true) {
            wait(10,SC_NS);
            s1.ACT.fire();
            wait(10,SC_NS);
            s1.ACT.fire();
            wait(10,SC_NS);
            s1.RD.fire();
            wait(10,SC_NS);
            s1.WR.fire();
            wait(10,SC_NS);
            s1.PRE.fire();
            wait(10,SC_NS);
            s1.ACT.fire();
            wait(10,SC_NS);
            s2.ACT.fire();
            wait(10,SC_NS);
            s2.ACT.fire();
            wait(10,SC_NS);
            s1.PRE.fire();
            wait(10,SC_NS);
            s2.PRE.fire();
            wait(10,SC_NS);
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
