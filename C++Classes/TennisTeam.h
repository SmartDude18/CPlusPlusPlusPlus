#pragma once
#include "SportsTeam.h"
class TennisTeam : public SportsTeam
{
public:
	TennisTeam();
	TennisTeam(std::string newName, int numWins) : SportsTeam(newName)
	{
		numberOfWins = numWins;
	}
	void Add(std::ostream& ostream, std::istream& istream) override;
	void Display(std::ostream& ostream) override;
	sport GetType() override { return sport::TENNIS; }
	int getNumWins();
	friend std::ostream& operator<<(std::ostream& os, const TennisTeam& team)
	{
		os << "Type:TennisTeam;" << "Name:" << team.name << ";NumberOfWins:" << team.numberOfWins << ";";
		return os;
	}
private:
	int numberOfWins;
};

