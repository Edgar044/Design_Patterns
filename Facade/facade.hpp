#ifndef FACADE_HPP
#define FACADE_HPP
#include <iostream>

//Engine Control Module
class ECM 
{

	bool ON = 0;
	bool OFF = 1;

public:
	std::string onECM() {
		ON = 1;
		OFF = 0;
		return " ECM is on!!!\n"; 
	}

	std::string offECM() {
		ON = 0;
		OFF = 1;
		return " ECM is off ???\n";
	}
};

class FuelPomp
{
	bool ON = 0;
	bool OFF = 1;

public:
	std::string onFuelPomp() {
		ON = 1;
		OFF = 0;
		return " Fuel pomp start work ->->->\n";
	}

	std::string offFuelPomp() {
		ON = 0;
		OFF = 1;
		return " Fuel pomp not working ()()()\n";
	}

};

class Starter
{
	bool ON = 0;
	bool OFF = 1;

public:
	std::string onStarter() {
		ON = 1;
		OFF = 0;
		return " Starter started spinning @@@\n";
	}

	std::string offStarter() {
		ON = 0;
		OFF = 1;
		return " Starter not spinning $$$\n";
	}
};

 


class StartStop
{
protected:
	ECM* _ecm;
	FuelPomp* _fuel_pomp;
	Starter* _starter;
	std::string EngineStatus = "";
public:


	StartStop(ECM* _ecm = nullptr, FuelPomp* _fuel_pomp = nullptr, Starter* _starter = nullptr) {
		this->_ecm = _ecm ? : new ECM;
		this->_fuel_pomp = _fuel_pomp ?: new FuelPomp;
		this->_starter = _starter ? : new Starter;
	}

	~StartStop() {
		delete _starter;
		delete _fuel_pomp;
		delete _ecm;
	}

	std::string startEngine() {
		EngineStatus = "";
		EngineStatus += this->_ecm->onECM();
		EngineStatus += this->_fuel_pomp->onFuelPomp();
		
		EngineStatus += _starter->onStarter();
		int engineSpeed = 0;
		while (engineSpeed < 1200) {
			
			engineSpeed += 100;
		}

		EngineStatus += _starter->offStarter() + " Engine Speed = " + std::to_string(engineSpeed) + "RPM\n";
		
		
		return EngineStatus;
	}

	std::string stopEngine() {
		EngineStatus = "";
		EngineStatus += this->_fuel_pomp->offFuelPomp();
		EngineStatus += this->_ecm->offECM();

		return EngineStatus;
	}

};

 

#endif //!FACADE_HPP
