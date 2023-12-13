// Day11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Car.h"
#include <vector>
#include <fstream>
#include "../../Day10/Day10/Hero.h"

int main()
{
	std::cout << "Gone in 60 Seconds!\n";//https://carbuzz.com/features/beyond-eleanor-gone-in-60-seconds-car-names#:~:text=The%20Complete%20List%20Of%20Gone%20In%2060%20Seconds,8%201961%20Porsche%20Speedster%20-%20%22Natalie%22%20More%20items


	std::vector<Car> garage;
	garage.push_back(Car(1967, "Ford", "Shelby Mustang GT500"));
	garage.push_back(Car(1956, "Ford", "T Bird"));
	garage.push_back(Car(1961, "Porsche", "Speedster"));
	garage.push_back(Car(1965, "Pontiac", "GTO"));
	garage.push_back(Car(1969, "Plymouth", "Hemi Cuda"));


	/*
		╔═════════════╗
		║ Serializing ║
		╚═════════════╝

		Saving the state (data) of objects

		Lecture Code: serialize the vector of Cars to a file.
			Data Format:
				separates cars. EX: car1|car2|car3
				separates data inside a car. EX: 1967;Ford;Shelby Mustang GT500

	*/
	std::string outFileName = "Gone.csv";
	std::ofstream outFile(outFileName);//open the file
	char delim = '\n';//car delimiter
	char insideDelim = '$';
	if (outFile.is_open())
	{
		std::cout << "MEMORY ADDRESSES\n";
		for (auto& car : garage)
		{
			car.serialize(outFile, insideDelim);
			std::cout << &car << "\n";
			if (&car != &(garage.back()))
				outFile << delim;
		}
		outFile.close();
	}

	std::cout << "\n\nMy Garage\n";
	for (auto& car : garage)
	{
		car.serialize(std::cout, '\t');
		//std::cout << &car << "\n";
		if (&car != &(garage.back()))
			std::cout << delim;
	}

	std::vector<Hero> JLA;
	JLA.push_back(Hero("Batman", "Bruce", 35));
	JLA.push_back(Hero("Aquaman", "Arthur Curry", 30));
	JLA.push_back(Hero("Joker", "Joe Kerr?" , 27));
	JLA.push_back(Hero("Wonder Woman", "Diana Prince", 35));
	JLA.push_back(Hero("Superman", "Clark Kent", 25));
	JLA.push_back(Hero("Shazam", "Billy", 12));
	//Serialize this vector to a file
	outFileName = "JLA.csv";
	outFile.open(outFileName);
	if (outFile.is_open())
	{
		for (auto& hero : JLA)
		{
			hero.serialize(outFile, insideDelim);
			if (&hero != &(JLA.back()))
				outFile << delim;
		}
		outFile.close();
	}


	/*
		╔═══════════════╗
		║ Deserializing ║
		╚═══════════════╝

		Recreating the objects from the saved state (data) of objects

		Lecture Code:
			Open the file
			Read in each line
			split each line to get each car
			split each car to get the car details

	*/

	outFileName = "Gone.csv";
	std::ifstream inFile(outFileName);
	std::vector<Car> myOtherGarage;
	if (inFile.is_open())
	{
		std::string carLine;
		while (std::getline(inFile, carLine, '\n'))
		{
			Car car(carLine, insideDelim);
			myOtherGarage.push_back(car);
		}
		inFile.close();
	}

	std::cout << "\n\nMy OTHER Garage\n";
	for (auto& myCar : myOtherGarage)
	{
		myCar.serialize(std::cout, '\t');
		if (&myCar != &(myOtherGarage.back()))
			std::cout << delim;
	}

	//Deserialize the JLA file to a new vector 
	std::vector<Hero> DC;
	std::string inFileName = "JLA.csv";
	std::ifstream inputFile(inFileName);
	if (inputFile.is_open())
	{
		std::string heroData;
		while (std::getline(inputFile, heroData))
		{
			Hero hero;
			hero.deserialize(heroData, insideDelim);
			DC.push_back(hero);
		}
	}
	std::cout << "\n\nDC\n";
	for (auto& hero : DC)
	{
		hero.serialize(std::cout, '\t');
		if (&hero != &(DC.back()))
			std::cout << delim;
	}
}