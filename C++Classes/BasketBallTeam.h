#pragma once
#include <iostream>
#include "SportsTeam.h"


class BasketBallTeam : public SportsTeam
{
public:
	BasketBallTeam();
	BasketBallTeam(std::string newName, int avgBaskets) : SportsTeam(newName)
	{
		averageBasketsPerGame = avgBaskets;
	}
	void Add(std::ostream& ostream, std::istream& istream) override;
	void Display(std::ostream& ostream) override;
	sport GetType() override { return sport::BASKETBALL; }
	float getBasketPerGame();
	friend std::ostream& operator<<(std::ostream& os, const BasketBallTeam& frac)
	{
		os << "Type:BasketBallTeam;" << "Name:"<<frac.name << ";AverageBasketsPerGame:" << frac.averageBasketsPerGame<<";";
		return os;
	}
private:
	float averageBasketsPerGame;
};

