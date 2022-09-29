#include <iostream>
#include <vector>
#include "Builder.h"
 

void client(Director &director)
{
	BMW_builder* bmw = new BMW_builder();
	director.set_buildr(bmw);
	std::cout<<"\nstandart complectation: \n";
	director.BuildBaseCar();

	BMW* bmw_standart = bmw -> Get_BMW();
	bmw_standart->show();
    
	std::cout<<"\nFull complectation\n";

	director.BuilFullCar();

	BMW *bmw_full = bmw -> Get_BMW();
    bmw_full->show();


}



int main(){
	
	Director *director = new Director();
	client(*director);
	delete director;


return 0;
}

