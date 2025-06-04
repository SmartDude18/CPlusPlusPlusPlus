#include "BasketBallTeam.h"

BasketBallTeam::BasketBallTeam() {}

void BasketBallTeam::Add(std::ostream& ostream, std::istream& istream)
{
	SportsTeam::Add(ostream, istream); 
	ostream << "What is their average number of baskets per game?: ";
	istream >> averageBasketsPerGame;
}

void BasketBallTeam::Display(std::ostream& ostream)
{
	SportsTeam::Display(ostream); 
	ostream << "Type: " << "Basketball" << std::endl;
	ostream << "Average Number of Baskets per game: " << averageBasketsPerGame << "\n" << std::endl;
}

float BasketBallTeam::getBasketPerGame()
{
	return averageBasketsPerGame;
}
