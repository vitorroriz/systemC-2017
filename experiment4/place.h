#ifndef PLACE
#define PLACE

#include "placeInterface.h"

template<unsigned int I=1, unsigned int O=1>
class Place : public placeInterface
{
private:
    unsigned int tokens;

public:
    Place(unsigned int tokens);
    void addTokens() override;
    void removeTokens() override;
    bool testTokens() override;

};

#endif // PLACE

