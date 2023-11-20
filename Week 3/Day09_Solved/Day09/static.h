#pragma once

#include <iostream>


void demo()
{
	static int count = 0; //created once
	std::cout << count << " ";
	count++;
}

class Car
{
private:
	Car(int year)
	{
		mModelYear = year;
		mNumberOfCarsMade++;
	}

public:

	int mModelYear; //each car has its own model year variable
	static int mNumberOfCarsMade; //shared by ALL cars

	static Car BuildCar(int yearToMake)
	{
		return Car(yearToMake);
	}
	static void reporting()
	{
		//std::cout << "Model year: " << mModelYear << "\n"; //ERROR! cannot access non-static members
		std::cout << "Number of cars made: " << mNumberOfCarsMade << "\n";
	}

	void vehicleInfo() //non-static methods have a hidden parameter called 'this'
	{
		std::cout << "Model Year: " << this->mModelYear << "\n";
	}
};

//initialize explicitly using the class name scoping
int Car::mNumberOfCarsMade = 0; 

