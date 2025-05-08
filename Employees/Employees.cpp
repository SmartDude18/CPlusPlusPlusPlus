// Employees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Employee.h";

int main()
{
    //Employee bossMan;

    //std::cout << bossMan << std::endl;

    int numEmployees;
    std::cout << "Number of employees (max 5): ";
    std::cin >> numEmployees;

    if (numEmployees > 5) numEmployees = 5; // Limit to 5 employees

    Employee employeeArr[5]; // Array of Employee objects

    for (int i = 0; i < numEmployees; i++) 
    {
        std::cout << "\nEnter details for Employee " << (i + 1) << ":\n";
        employeeArr[i].setValues();
    }

    for (int i = 0; i < numEmployees; i++)
    {
        std::cout << employeeArr[i] << std::endl;
    }
    return 0;
}