#include <iostream>
#include <vector>

class SymbolTable
{
protected:
	static SymbolTable* symbol_table;
	  

	std::vector <std::string> _name;
	std::vector <int> _data;
	 

public:

	void operator=(const SymbolTable&) = delete; //delete Assignment
	SymbolTable(SymbolTable& other) = delete;// delete copy constructor
	~SymbolTable() = default;

	 
	
	static SymbolTable* getInstance() {
		
		if (symbol_table == NULL) {
			symbol_table = new SymbolTable();
		} 

		return symbol_table;
	}

	void add(std::string name, int data) {

		_name.push_back(name);
		_data.push_back(data);
		//++size;


	}

	void printData() {
		for (size_t i = 0; i < _data.size(); ++i) {
			std::cout <<_name[i] << " = " << _data[i] << "\n";
		}
		
	} 

protected:
	SymbolTable() = default;
  
};
 

SymbolTable* SymbolTable::symbol_table = nullptr;
