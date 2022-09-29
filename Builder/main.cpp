#include <iostream>
#include <vector>


class BMW
{

	public:
	std::vector <std::string> parts_;
	void show(){
		std::cout<< "Your car heave: \n";
		for(auto i = 0; i < parts_.size(); ++i){
			if(parts_[i] != parts_.back()){
				std::cout << i + 1 <<". "<< parts_[i] <<"\n";
			} else {
				std::cout << i + 1 <<". "<< parts_[i] << "\n !!!!!Now You can drive your car!!!!! \n\n\n";
			}
		}
	}

};


 

class CarBuilder
{
	public:
	virtual ~CarBuilder(){}; 
	//main 
	virtual void buildBody() const = 0;
	virtual void buildDoors() const = 0;
	virtual void buildCoolor() const = 0;
	virtual void buildTiers() const = 0;
    virtual void buildEngine() const = 0;

	//optional
	virtual void buildMultimedia() const = 0;
	virtual void buildBoardComputer() const =0;
	virtual void buildTRC() const = 0;
	virtual void buildABS() const = 0;	
 

};

class BMW_builder : public CarBuilder
{
	private:

	BMW *bmw;

	public:

	BMW_builder(){
		this->Reset();
	}

	~BMW_builder(){
		delete bmw;
	}

	void Reset(){
		this->bmw = new BMW();
	}

    void buildBody()const override{this->bmw->parts_.push_back("car body created\n");}
    void buildDoors()const override{this->bmw->parts_.push_back("car Doors in place\n");}
	void buildCoolor()const override{this->bmw->parts_.push_back("car is painted\n");}
	void buildTiers()const override{this->bmw->parts_.push_back("car tiers in place\n");}
    void buildEngine()const override{this->bmw->parts_.push_back("Engine ready to work\n");}

	//optional
	void buildMultimedia()const override{this->bmw->parts_.push_back("Multimedia is install\n");}
	void buildBoardComputer()const override{this->bmw->parts_.push_back("Board Computer ready\n");}
	void buildTRC()const override{this->bmw->parts_.push_back("Treaction control ready to save you in roada\n");}
	void buildABS()const override{this->bmw->parts_.push_back("ABS is included on your car\n");}


	BMW* Get_BMW(){
		BMW * result = this->bmw;
		this->Reset();
		return result;
	}
};

class Director {
	private:
	CarBuilder* carBuilder;

	public:
	void set_buildr(CarBuilder *builder){
		this->carBuilder = builder;
	}

	void BuildBaseCar(){
		this->carBuilder->buildBody();
		this->carBuilder->buildDoors();
		this->carBuilder->buildCoolor();
		this->carBuilder->buildTiers();
		this->carBuilder->buildEngine();

	}
    //ste improvizacia ka petqa chshtel
	void BuilFullCar(){
		this->BuildBaseCar();
		this->carBuilder->buildABS();
		this->carBuilder->buildBoardComputer();
		this->carBuilder->buildMultimedia();
		this->carBuilder->buildTRC();

	}
};


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

