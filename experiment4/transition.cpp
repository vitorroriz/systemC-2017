#include <iostream>
#include "transition.h"

template<unsigned int N, unsigned int M>
void transition<N,M>::fire()
{
    bool can_fire = true;
    /*
    std::cout << sc_time_stamp() << "  -------- entry ----------------------------------" << std::endl;
    std::cout << this->name() << " in #tokens = " << in->testTokens() << std::endl;
    std::cout << this->name() << " out #tokens = " << out->testTokens() << std::endl;
    */
    for(unsigned int i = 0 ; i < N ; ++i) {
     //   std::cout << " testToken of in" << i << " = " << in[i]->testTokens() << std::endl;
        if(!in[i]->testTokens()) {
                can_fire = false;
                break;
        }
    }
    if(can_fire) {
        for(unsigned int i = 0 ; i < N ; ++i)
            in[i]->removeTokens();
        for(unsigned int i = 0 ; i < M ; ++i)
            out[i]->addTokens();
        std::cout << this->name() << ": Fired" << std::endl;
    }
    else {
        std::cout << this->name() << ": NOT Fired" << std::endl;
    }
    /*
    std::cout << " -------- exit ------------------------------------" << std::endl;
    std::cout << this->name() << " in #tokens = " << in->testTokens() << std::endl;
    std::cout << this->name() << " out #tokens = " << out->testTokens() << std::endl;
    std::cout << std::endl;
    */
}
