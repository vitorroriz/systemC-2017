#ifndef PLACE
#define PLACE

#include "placeInterface.h"

    class Place : placeInterface
    {
        private:
            unsigned int tokens;

        public:
            Place();
            void addTokens(unsigned int) override;
            void removeTokens(unsigned int) override;
            unsigned int testTokens() override;

    };

#endif // PLACE

