// DiceGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DiceGameHandler.h";

void updateDisplay(DiceGameHandler currentGame)
{
	for (int i = 0; i < currentGame.getPlayerArray().size(); i++)
	{
		std::cout << "player " + std::to_string(i +  1) + " " + std::to_string(currentGame.getPlayerArray()[i].getTotalScore()) << std::endl;
	}
}
int main()
{
	int numberOfPlayers;
	std::cout << "How many players?" << std::endl;
	std::cin >> numberOfPlayers;
	int dieSize;
	std::cout << "What sided die would you like to play with?" << std::endl;
	std::cin >> dieSize;
	int amountOfDice;
	std::cout << "How many of these dice would you like?" << std::endl;
	std::cin >> amountOfDice;
	int amountOfRounds;
	std::cout << "How many rounds?" << std::endl;
	std::cin >> amountOfRounds;
	DiceGameHandler handler(numberOfPlayers, dieSize, amountOfDice, amountOfRounds);//int numberOfPlayers, int dieSize, int amountOfDice, int amountOfRounds
	for (int i = 0; i < amountOfRounds;i++)
	{
		for (int j = 0; j < numberOfPlayers; j++)
		{
			handler.nextTurn();
		}
		updateDisplay(handler);
		system("pause");
		std::cout << " " << std::endl;
	}
	handler.getWinners();
	std::cout << handler.getWinnerTxt() + " Wins!" << std::endl;
}


