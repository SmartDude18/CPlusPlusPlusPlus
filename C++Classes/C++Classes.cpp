// C++Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Database.h"
#include <string>

SportsTeam::sport getType()
{
    std::cout << "Enter type (0 for BasketBall, 1 for Tennis): ";
    int type;
    std::cin >> type;
    return static_cast<SportsTeam::sport>(type);
}

int main()
{
    Database* dataHold = new Database();
    while (true)
    {
        std::cout << "1: Create\n2: Display All\n3: Display by Name\n4: Display by Type\n5: Quit\n";
        int choice;
        std::cin >> choice;
        switch (choice)
        {
            case 1:
            {
                dataHold->Create(getType());
                break;
            }
            case 2:
            {
                dataHold->DisplayAll();
                break;
            }
            case 3:
            {
                std::cout << "What name are you looking for?: ";
                std::string searchName;
                std::cin >> searchName;
                dataHold->Display(searchName);
                break;
            }
            case 4:
            {
                dataHold->Display(getType()); 
                break;
            }
            case 5:
            {
                delete dataHold;
                exit;
            }
        }
    }
}
