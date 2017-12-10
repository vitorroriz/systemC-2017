#include "state_machine.h"
#include <unistd.h>
#include <iostream>

// TODO
void stateMachine::process()
{
	switch(state)
	{
    case Start:
		switch(input)
		{
		case 'A':
		case 'C':
		case 'T':
			state = Start;
			break;
		case 'G':
			state = G;
            break;
		}
		break;

	case G:
		switch(input)
		{
		case 'G':
			state = G;
			break;
		case 'C':
		case 'T':
			state = Start;
			break;
		case 'A':
			state = GA;
			break;
		}
		break;

	case GA:
		switch(input)
		{
		case 'C':
		case 'T':
			state = Start;
			break;
		case 'G':
			state = G;
			break;
		case 'A':
			state = GAA;
			break;
		}
		break;

	case GAA:
		switch(input)
		{
		case 'A':
		case 'C':
		case 'T':
			state = Start;
			break;
		case 'G':
			state = GAAG;
			break;
		}
		break;

	case GAAG:
        pattern_counter++;
        std::cout << "Sequence GAAG detected at string position [" << pattern_pos << "]" << std::endl;
        std::cout << "Number of occurences = [" << pattern_counter << "]" << std::endl;
        std::cout << "Frequency of occurences = ["  << (float(pattern_counter)/float(pattern_pos)) << "] sequences/nucleotide bases" << std::endl << std::endl;
        switch(input)
		{
		case 'A':
		case 'C':
		case 'T':
			state = Start;
			break;
		case 'G':
			state = G;
			break;
		}
		break;
	}

    pattern_pos++;
}
