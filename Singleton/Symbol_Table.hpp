#include <iostream>
#include <vector>

class SymbolTable
{
protected:
    static SymbolTable* symbol_table;
    
	
	std::string _name;
	int _data; 
    //int size = 0;

public:

void operator=(const SymbolTable &) = delete; //delete Assignment
SymbolTable (SymbolTable &other) = delete;// delete copy constructor

//function getInstance for initilization object
static SymbolTable* getInstance(const std::string &name, const int &data ){
	if(symbol_table == NULL){
		symbol_table  = new SymbolTable(name, data);
	}

	return symbol_table;

}

void printData(){
	std::cout << _name << ", " << _data << "\n";
}

protected:
SymbolTable(const std::string &name, const int &data){
		_name  = name;
		_data  = data;

	}
};