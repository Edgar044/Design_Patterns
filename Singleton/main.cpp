#include <iostream>
#include <vector>
#include "Symbol_Table.hpp"


void foo() {
	SymbolTable* a = SymbolTable::getInstance();
	a->add("lastVariable", 9999);
	a->printData();
}




int main(){
    
	SymbolTable* a = SymbolTable::getInstance();
	
	a->add("a", 5);
	a->add("t",0);
	a->add("j", 8);
	a->add("a", 78);
	a->add("a",900);
	

	foo();
	
	return 0;
}