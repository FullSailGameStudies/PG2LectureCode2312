// Day09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "static.h"
#include "abstract.h"

/*
Nested class
Abstract class
Static members
Final members
Friends
*/

int main()
{

    /*
        ╔════════════════════╗
        ║  Static Variables  ║
        ╚════════════════════╝


    */
    for (size_t i = 0; i < 10; i++)
    {
        //int j = 10;
        //j++;
        //std::cout << j << "\n";

        demo();
        //std::cout << count << "\n";
    }

    //Weapon wpn;
    Grenade frag;


    /*
        ╔══════════════════╗
        ║  Static Members  ║
        ╚══════════════════╝

        When calling a non-static method on a class, you must use a variable of that class.
        That's because the variable is passed in as the 'this' parameter.

        Static methods do not have a 'this' parameter therefore you call them on the 
        class name itself.

        That's also why static methods cannot access non-static members.

    */

    std::cout << ++Car::mNumberOfCarsMade << "\n";

    Car myRide(1988);
    Car::reporting();//no object gets passed in
    Car gt(2025);
    gt.vehicleInfo();
    myRide.vehicleInfo();//calling non-static methods. myRide is passed in for 'this'

    /*
    
        CHALLENGE:
        Add a static method to the Car class that returns an instance of the Car class.
    
    */
}