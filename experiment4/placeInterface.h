#ifndef PLACEINTERFACE
#define PLACEINTERFACE
#include <systemc.h>

class placeInterface : public sc_interface {
public:

    virtual void addTokens() = 0;
    virtual void removeTokens() = 0;
    virtual bool testTokens() = 0;

};

#endif // PLACEINTERFACE

