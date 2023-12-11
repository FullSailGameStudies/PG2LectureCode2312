#include "Pistol.h"
#include <iostream>

void Pistol::showMe()
{
	Weapon::showMe();//EXTEND the base

	std::cout << "Rounds: " << rounds_ << 
		" Mag Capacity: " << magCapacity_ << "\n";

}
