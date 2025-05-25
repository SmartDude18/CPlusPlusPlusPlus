#pragma once
#include "SportsTeam.h"
class TennisTeam : public SportsTeam
{
public:
	void Add(std::ostream& ostream, std::istream& istream) override;
	void Display(std::ostream& ostream) override;
	sport GetType() override { return sport::TENNIS; }
	int getNumWins();
private:
	int numberOfWins;
};

