#include <iostream>
#include <vector>
#include "Symbol_Table.hpp"



int main(){

    
	SymbolTable* a = SymbolTable::getInstance("x",5);
    
	a->printData();
	
 


	return 0;
}