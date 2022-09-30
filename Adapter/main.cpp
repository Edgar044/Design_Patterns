#include <iostream>
#include "Adapter.h"


int main(){

	RoundHole *Hole_1 = new RoundHole(9);
	RoundPeg  *rPeg_1 = new RoundPeg(10);

	std::cout << Hole_1->fits(rPeg_1) << "\n";
    
	RoundHole* Hole_2 = new RoundHole(10);
	RoundPeg* rPeg_2  = new RoundPeg(10);

	std::cout << Hole_2->fits(rPeg_2) << "\n";


	return 0;
}