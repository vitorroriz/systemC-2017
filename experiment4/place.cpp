#include "place.h"

Place::Place()
{
    tokens = 0;
}

void Place::addTokens(unsigned int n)
{
    tokens += n;
}

void Place::removeTokens(unsigned int n)
{
     tokens -= n;
}

unsigned int Place::testTokens()
{
    return this->tokens;
}
