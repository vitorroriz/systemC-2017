#include "place.h"

template<unsigned int I, unsigned int O>
Place<I,O>::Place(unsigned int tokens)
{
    this->tokens = tokens;
}

template<unsigned int I, unsigned int O>
void Place<I,O>::addTokens()
{
    tokens = tokens + I;
}

template<unsigned int I, unsigned int O>
void Place<I,O>::removeTokens()
{
    tokens = tokens - O;
}

template<unsigned int I, unsigned int O>
bool Place<I,O>::testTokens()
{
    return this->tokens >= O? true : false;
}
