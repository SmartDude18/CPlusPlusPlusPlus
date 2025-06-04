// FractionAssignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Fraction.h"

void displayBool(bool display)
{
    if (display)
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }
}


int main()
{
    Fraction<int> newFract(1,4);

    Fraction<int> newFract2;
    std::cin >> newFract2;

    std::cout << "1/4 + "<< newFract2<< ": "<< (newFract + newFract2) << std::endl;
    std::cout << "1/4 - " << newFract2 << ": " << (newFract - newFract2) << std::endl;
    std::cout << "1/4 * " << newFract2 << ": " << (newFract * newFract2) << std::endl;
    std::cout << "1/4 / " << (newFract / newFract2) << std::endl;


    std::cout << "1/4 is " << newFract2 << ": ";
    displayBool(newFract == newFract2);
    std::cout << "1/4 is not "<< newFract2 << ": ";
    displayBool(newFract != newFract2);
    std::cout << "1/4 is less than " << newFract2 << ": ";
    displayBool(newFract < newFract2);
    std::cout << "1/4 is less than or equal to " << newFract2 << ": ";
    displayBool(newFract <= newFract2);
    std::cout << "1/4 is greater than " << newFract2 << ": ";
    displayBool(newFract > newFract2);
    std::cout << "1/4 is greater than or equal to " << newFract2 << ": ";
    displayBool(newFract >= newFract2);
    std::cout << newFract2 << " as a double: " << newFract2.toDouble() << std::endl;

}
