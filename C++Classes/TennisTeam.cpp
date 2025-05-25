#include "TennisTeam.h"

void TennisTeam::Add(std::ostream& ostream, std::istream& istream)
{
	SportsTeam::Add(ostream, istream); 
	ostream << "How many matches have they won?: ";
	istream >> numberOfWins;
}

void TennisTeam::Display(std::ostream& ostream)
{
	SportsTeam::Display(ostream);
	ostream << "Type: " << "Tennis" << std::endl;
	ostream << "Wins: " << numberOfWins << "\n" << std::endl;
}

int TennisTeam::getNumWins()
{
	return numberOfWins;
}
