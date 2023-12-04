#pragma once
#include <string>
class Person
{
public:
	std::string Name() const;
	void Name(const std::string& name);

	int Age() const;
	void Age(int age);



private:
	std::string name_;
	int age_;
};

