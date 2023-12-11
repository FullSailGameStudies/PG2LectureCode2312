#pragma once

#include <iostream>

int gOtherCount = 0;

void demo()
{
	static int count = 0; //created once
	std::cout << count << " ";
	count++;
}

class Car
{
public:
	Car(int year)
	{
		mModelYear = year;
		mNumberOfCarsMade++;
	}

	int mModelYear; //each car has its own model year variable
	static int mNumberOfCarsMade; //shared by ALL cars

	//static method CANNOT access non-static members
	//static method CAN access static members
	static void reporting() //no 'this' available
	{
		//std::cout << "Model year: " << mModelYear << "\n"; //ERROR! cannot access non-static members
		std::cout << "Number of cars made: " << mNumberOfCarsMade << "\n";
	}

	//non-static method CAN access non-static members
	//non-static method CAN access static members
	//non-static: there's a hidden parameter called 'this'
	void vehicleInfo() //Car* this
	{
		std::cout << "Model Year: " << mModelYear << "\n";
	}
};

//initialize explicitly using the class name scoping
int Car::mNumberOfCarsMade = 0; 

