#ifndef PLACEINTERFACE
#define PLACEINTERFACE
#include <systemc.h>

    class placeInterface : sc_interface {
    public:

        virtual void addTokens(unsigned int n) = 0;
        virtual void removeTokens(unsigned int n) = 0;
        virtual unsigned int testTokens() = 0;

    };

#endif // PLACEINTERFACE

