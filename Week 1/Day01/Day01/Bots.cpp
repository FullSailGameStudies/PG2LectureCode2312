#include "Bots.h"
#include <iostream>

//a DEFINITION for the method
void CleaningBot::CleanRoom(std::string roomToClean)
{
	std::cout << "Wrrrrr...Cleaning the " << roomToClean << " room.\n";
	std::cout << "DONE!\n";
}

void CleaningBot::BotReport()
{
	std::cout << "There are x cleaning bots\n";
}
