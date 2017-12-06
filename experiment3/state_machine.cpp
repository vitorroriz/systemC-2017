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
            std::cout << "Sequence GAAG detected" << std::endl;
			break;
		}
		break;
	case GAAG:
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
}
