#pragma once
#include <string>
#include <vector>

class CleaningBot
{
public:
	//return type  Name  (parameter list)
	//a non-static method
	void CleanRoom(std::string roomToClean); //the DECLARATION

	static void BotReport();
};

class CookingBot
{
public:
	std::string CookMeal(std::string food, std::vector<std::string> ingredients);
};

