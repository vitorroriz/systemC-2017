#ifndef EXOR_H
#define EXOR_H

#include "systemc.h"
#include "nand.h"

using namespace std;
// TODO: Insert your code here
SC_MODULE(exor)
{

    sc_in<bool>	A;
    sc_in<bool>	B;
	sc_out<bool>	Z;
	
    sc_signal<bool>	h1, h2, h3;

	nand n_a, n_b, n_c, n_d;

	SC_CTOR(exor) : A("A"), B("B"), Z("Z"), h1("h1"), h2("h2"), h3("h3"), n_a("n_a"), n_b("n_b"), n_c("n_c"), n_d("n_d")
	{
		n_a.A(A);
		n_a.B(B);
		n_a.Z(h1);

		n_b.A(h1);
		n_b.B(B);
		n_b.Z(h2);

		n_c.A(A);
		n_c.B(h1);
		n_c.Z(h3);

		n_d.A(h2);
		n_d.B(h3);
		n_d.Z(Z);
		
	}



};
#endif // EXOR_H
