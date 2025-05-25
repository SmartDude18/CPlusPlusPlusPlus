#include "SportsTeam.h"
#include <string>
#include <iostream>
std::string SportsTeam::getName()
{
	return name;
}

void SportsTeam::Add(std::ostream& ostream, std::istream& istream)
{
	ostream << "What is the name for this? (without spaces): ";
	std::string holdString;
	istream >> holdString;
	name = holdString;
}

void SportsTeam::Display(std::ostream& ostream)
{
	ostream << "Name: " << name << std::endl;
}