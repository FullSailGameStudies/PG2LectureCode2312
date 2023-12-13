#pragma once
#include <string>
#include <fstream>
#include <sstream>
class Hero
{
public:
	Hero() {}
	Hero(std::string name, std::string secret, int age)
		: Name(name), Secret(secret), Age(age)
	{	}
	std::string Name;
	std::string Secret;
	int Age;

	void serialize(std::ostream& outputFile, char delimiter)
	{
		outputFile << Name << delimiter << Secret << delimiter << Age;
	}
	void deserialize(std::string data, char delimiter)
	{
		std::stringstream dataStream(data);
		std::getline(dataStream, Name, delimiter);
		std::getline(dataStream, Secret, delimiter);
		std::string ageStr;
		std::getline(dataStream, ageStr, delimiter);
		Age = std::stoi(ageStr);
	}
};

