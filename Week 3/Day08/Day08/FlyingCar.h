#pragma once
#include "Car.h"
class FlyingCar : public Car
{
public:
	//ctors
	//flyingcar constructor MUST call a Car constructor
	FlyingCar(int year, std::string make, std::string model, float maxAlt) : 
		Car(year,make,model),//base ctor FIRST
		maxAltitude_(maxAlt)
	{
		std::cout << mModel;
	}

private:
	float maxAltitude_;
};

