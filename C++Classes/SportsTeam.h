#pragma once
#include <iostream>
#include <string>
class SportsTeam
{
public:
	SportsTeam();
	SportsTeam(std::string);
	enum sport
	{
		BASKETBALL,
		TENNIS
	};
	std::string name;

	virtual void Add(std::ostream& ostream, std::istream& istream);
	virtual void Display(std::ostream& ostream);

	std::string getName();
	virtual sport GetType() = 0;
};

