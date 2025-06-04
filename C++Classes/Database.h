#pragma once
#include <vector>
#include "SportsTeam.h"

class Database
{
private:
	std::vector<SportsTeam*> data;

public:
	~Database(); 
	Database();
	void Create(SportsTeam::sport type);
	void DisplayAll();
	void Display(const std::string& name);
	void Display(SportsTeam::sport type);
};

