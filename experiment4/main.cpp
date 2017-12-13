#include <systemc.h>
#include "transition.h"
#include "transition.cpp"
#include "place.h"
#include "place.cpp"




// TOPLEVEL
SC_MODULE(toplevel)
{
    public:
    transition<1,2> t1;
    transition<2,1> t2;
    transition<1,1> t3;
    Place<1,1> p1, p2, p3, p4;
    SC_CTOR(toplevel) : t1("t1"), t2("t2"), t3("t3"),
        p1(1), p2(0), p3(0), p4(0)
    {
        SC_THREAD(process);
    t1.in.bind(p1);
    t1.out.bind(p2);
    t1.out.bind(p3);
    t2.in.bind(p2);
    t2.in.bind(p4);
    t2.out.bind(p1);
    t3.in.bind(p3);
    t3.out.bind(p4);

    }
    void process() {
        while(true) {
            wait(10,SC_NS);
            t1.fire();
            wait(10,SC_NS);
            t2.fire();
            wait(10,SC_NS);
            t3.fire();
            wait(10,SC_NS);
            t2.fire();
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
