#include "stimuli.h"

void stimuli::process()
{
    if(counter <= sequence.length())
    {
        std::string data = sequence.substr(counter,1);
        output.write(data.c_str()[0]);
        counter++;
    }
    else
    {
        sc_stop();
    }
}
