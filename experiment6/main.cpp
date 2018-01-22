#include <systemc>
#include <iostream>
#include <iomanip>
#include "memory.h"
#include "processor.h"


int sc_main (int __attribute__((unused)) sc_argc,
             char __attribute__((unused)) *sc_argv[])
{
#ifdef USE_QK
    processor cpu0("cpu0","/home/vitorroriz/systemc-repo/experiment6/random1.txt", sc_time(1,SC_NS));
    processor cpu1("cpu1","/home/vitorroriz/systemc-repo/experiment6/random2.txt", sc_time(1,SC_NS));
#else
    processor cpu0("cpu0","/home/vitorroriz/systemc-repo/experiment6/stimuli1.txt", sc_time(1,SC_NS));
    processor cpu1("cpu1","/home/vitorroriz/systemc-repo/experiment6/stimuli2.txt", sc_time(1,SC_NS));
#endif


    memory<1024> memory0("memory0");
    memory<1024> memory1("memory1");

    cpu0.iSocket.bind(memory0.tSocket);
    cpu1.iSocket.bind(memory1.tSocket);

    std::cout << std::endl << "Name "
              << std::setfill(' ') << std::setw(10)
              << "Time" << " "
              << std::setfill(' ') << std::setw(5)
              << "CMD" << "   "
              << std::setfill(' ') << std::setw(8)
              << "Address"
              << "   " << std::hex
              << std::setfill(' ') << std::setw(8)
              << "Data"
              << " " << std::endl
              << "-------------------------------------------"
              << std::endl;

    sc_start();

    std::cout << std::endl;
    return 0;
}
