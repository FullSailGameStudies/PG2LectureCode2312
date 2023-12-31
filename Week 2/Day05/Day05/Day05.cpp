﻿// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

enum class Weapon
{
	Sword, Axe, Spear, Mace
};

int LinearSearch(/*what are we searching in*/std::vector<int> scores,
	/*what are we searching for*/int someNum)
{
	int index = -1;

	for (size_t i = 0; i < scores.size(); i++)
	{
		if (scores[i] == someNum)
		{
			index = i;
			break;
		}
	}

	return index;
}

int main()
{
	/*
		╔═════════╗
		║Searching║
		╚═════════╝

		There are 2 ways to search a vector: linear search or binary search

		CHALLENGE 1:

			write a method to linear search the numbers list.
				The method should take 2 parameters: vector of ints to search, int to search for.
				The method should return -1 if NOT found or the index if found.

			The algorithm:
				1) start at the beginning of the vector
				2) compare each item in the vector to the search item
				3) if found, return the index
				4) if reach the end of the vector, return -1 which means not found

	*/
	std::vector<int> numbers = { 0,1,2,3,4,5,6 };
	int searchNumber = 0;
	int foundIndex = LinearSearch(numbers, searchNumber);
	if (foundIndex != -1)
		std::cout << searchNumber << " was found at index " << foundIndex << "\n";
	else
		std::cout << searchNumber << " was not found.\n";



	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Creating a map  ]

		map<TKey, TValue>  - an associative collection.
			TKey is a placeholder for the type of the keys.
			TValue is a placeholder for the type of the values.

		When you want to create a map variable,
			1) replace TKey with whatever type of data you want to use for the keys
			2) replace TValue with the type you want to use for the values


		[  Adding items to a map  ]

		There are 2 ways to add items to a Dictionaruy:
		1) using the insert method.
		3) using [key] = value
	*/

	std::map<std::string, float> menu;
	auto wasInserted = menu.insert(std::pair<std::string, float>("Cuban Sandwich", 12.57F));
	if (wasInserted.second)//was it inserted?
	{
		std::cout << "The cuban was added to the menu.\n";
	}
	else
		std::cout << "The cuban was already on the menu.\n";

	menu["Chicken Caesar Wrap"] = 6.50F;//overwrite any existing value
	menu["'Bottomless' Boneless Buffalo Wings"] = 14.99F;//overwrite any existing value
	menu["Fried Rice"] = 7.99F;//overwrite any existing value


	std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

	//returns an iterator and a bool. 
	//if the key is already in the map, it will NOT insert it -- the bool will be false.
	auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
	if (inserted.second == false) //meaning not inserted
		std::cout << "The key was already in the map. It was not inserted.\n";
	else
		std::cout << "The key was inserted in the map.\n";

	dorasBackpack[Weapon::Axe] = 3;
	dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map





	std::vector<std::string> students{ "Candace", "Josh", "Daniel", "Ana", "Lucas", "Jamauri", "Harold", "Bryan", "David", "Will", "Mitchell",
	"Johnny", "Kasey", "Jonathan", "Nasir", "Chanaya", "Diogo",
	"Akheem","Antony","Arnold","Christopher","Jackson","Jason","Zachary" };


	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Looping over a map  ]

		You should use a ranged-based for loop when needing to loop over the entire map.

	*/
	for (auto const& [key, val] : dorasBackpack) //requires C++ 20
	{
		switch (key)
		{
		case Weapon::Sword:
			std::cout << "Sword: ";
			break;
		case Weapon::Axe:
			std::cout << "Axe: ";
			break;
		case Weapon::Spear:
			std::cout << "Spear: ";
			break;
		case Weapon::Mace:
			std::cout << "Mace: ";
			break;
		default:
			break;
		}
		std::cout << val << "\n";
	}


	std::cout << "\n Welcome to G's Cafe \n";
	for (auto iter = menu.begin(); iter != menu.end(); iter++)
	{
		std::cout << std::setw(8) << iter->second << " " << iter->first << "\n";
	}


	std::cout << "\n Welcome to G's Cafe \n";
	for (const auto& [menuItem, itemPrice] : menu)
	{
		std::cout << std::setw(8) << itemPrice << " " << menuItem << "\n";
	}



	/*
		CHALLENGE 2:

			Create a map that stores names (string) and grades.
			Call the variable grades.
			Add students and grades to your map.

	*/
	/*
		CHALLENGE 3:

			Loop over your grades map and print each student name and grade.

	*/
	srand(time(NULL));
	std::map<std::string, double> grades;
	for (auto& name : students)
	{
		grades[name] = (rand() % 10001) / 100.0F;
	}

	std::cout << "\n\n$_$_$  PG2 December 2023  $_$_$\n";
	for (auto& [student,grade] : grades)
	{
		std::cout << std::setw(15) << std::left << student << std::setw(8) << std::right << grade << "\n";
	}



	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Checking for a key in a map  ]

		use the find method to check if the key is in the map

		will return map.end() if NOT found.

	*/
	std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
	if (foundIter == dorasBackpack.end()) //meaning it was NOT found
	{
		std::cout << "Dora did not find any maces.\n";
	}
	else
	{
		//can safely grab the value for the key
		std::cout << "Dora found " << foundIter->second << " Maces\n";
	}

	std::string itemToLookup = "Big Mac";//a key
	auto menuItemFound = menu.find(itemToLookup);
	if (menuItemFound == menu.end())
		std::cout << "Sorry, " << itemToLookup << " is not on the menu. Try McDonald's.\n";
	else
		std::cout << itemToLookup << " costs " << menuItemFound->second << ".\n";

	/*
		CHALLENGE 5:

			look for a specific student in the map.
			If the student is found, print out the student's grade
			else print out a message that the student was not found

	*/
	std::string studentToFind = "Josh";
	auto wasFound = grades.find(studentToFind);
	if (wasFound != grades.end())
	{
		std::cout << studentToFind << " has a grade of " << wasFound->second << ".\n";
	}
	else
		std::cout << studentToFind << " is not in PG2 this month.\n";




	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Updating a value for a key in a map  ]

		To update an existing value in the map, use the [ ]


	*/
	dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe

	itemToLookup = "Fried Rice";
	menuItemFound = menu.find(itemToLookup);
	if (menuItemFound != menu.end())
	{
		std::cout << itemToLookup << " was " << menuItemFound->second;
		menuItemFound->second *= 1.05F;
		std::cout << ". Now it costs " << menuItemFound->second << "! Thanks Putin.\n";
	}


	/*
		CHALLENGE 6:

			Pick any student and curve the grade (add 5) that is stored in the grades map

	*/
	studentToFind = "Harold";
	wasFound = grades.find(studentToFind);
	if (wasFound != grades.end())
	{
		std::cout << studentToFind << " had a grade of " << wasFound->second << ". Now the grade is ";
		wasFound->second = std::min<float>(100.0F, wasFound->second + 5);
		std::cout << wasFound->second << ".\n";
	}


	itemToLookup = "Chicken Nuggies";
	size_t numRemoved = menu.erase(itemToLookup);
	if (numRemoved > 0)
		std::cout << itemToLookup << " was removed from the menu. No Kids allowed!\n";

	menuItemFound = menu.find(itemToLookup);
	if (menuItemFound != menu.end())
	{
		auto nextItemInMap = menu.erase(menuItemFound);
	}

}