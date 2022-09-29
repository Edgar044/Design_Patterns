#include <iostream>
#include <vector>
#include "Symbol_Table.hpp"


void foo() {
	SymbolTable* ST = SymbolTable::getInstance();
	ST->add("lastVariable", 9999);
	ST->printData();
}




int main(){
    
	SymbolTable* ST = SymbolTable::getInstance();
	
	ST->add("a", 5);
	ST->add("b",0);
	ST->add("c", 8);
	ST->add("d", 78);
	ST->add("e",900);
	

	foo();
	
	return 0;
}