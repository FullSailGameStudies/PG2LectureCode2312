#include "Person.h"

std::string Person::Name() const
{
    return name_;
}

void Person::Name(const std::string& name)
{
    if (name.size() > 0 && name.size() < 25)
        name_ = name;
}

int Person::Age() const
{
    return age_;
}

void Person::Age(int age)
{
    if (age >= 0 && age <= 120)
        age_ = age;
}
