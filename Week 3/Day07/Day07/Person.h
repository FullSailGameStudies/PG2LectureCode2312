#pragma once
#include <string>
class Person
{
public:
	std::string Name() const;
	void Name(const std::string& name);

	int Age() const;
	void Age(int age);

	Person(const std::string& name, int age) 
	{
		Name(name);
		Age(age);
	}

private:
	std::string name_;
	int age_;
};

