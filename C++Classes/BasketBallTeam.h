#pragma once
#include <iostream>
#include "SportsTeam.h"


class BasketBallTeam : public SportsTeam
{
public:
	void Add(std::ostream& ostream, std::istream& istream) override;
	void Display(std::ostream& ostream) override;
	sport GetType() override { return sport::BASKETBALL; }
	float getBasketPerGame();
private:
	float averageBasketsPerGame;
};

