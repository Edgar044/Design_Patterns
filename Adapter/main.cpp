#include <iostream>
#include "Adapter.h"


int main(){
	RoundHole *Hole = new RoundHole(9);
	RoundPeg *rPeg = new RoundPeg(10);

	std::cout << Hole->fits(rPeg) <<"\n";
 

	return 0;
}