#include <iostream>
#include "facade.hpp"

 
int main() {
	 
	StartStop ST;
	std::cout << ST.startEngine();
	std::cout << " A ->->->-> B\n";
	std::cout << ST.stopEngine();

	return 0;
}

 