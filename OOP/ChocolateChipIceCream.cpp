#include "ChocolateChipIceCream.h"
#include <iostream>

void ChocolateChipIceCream::lick()
{
	if (amountOfChips == 0)
	{
		std::cout << "What is this?! Chocolate Chip Ice Cream with no chips?!" << std::endl;
	}
	else if (amountOfChips < 5)
	{
		std::cout << "Lackluster amount of chocolate these days" << std::endl;
	}
	else if (amountOfChips < 10)
	{
		std::cout << "Solid amount of chocolate... Tasty!" << std::endl;
	}
	else if (amountOfChips < 20)
	{
		std::cout << "So much chocolate!" << std::endl;
	}
	else if (amountOfChips >= 20)
	{
		std::cout << "TOO MUCH CHOCOLATE..... OVERFLOWWWIIINNNGGGG" << std::endl;
	}
}
