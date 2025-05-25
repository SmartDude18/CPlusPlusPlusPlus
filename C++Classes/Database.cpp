#include "Database.h"
#include "SportsTeam.h"
#include "BasketBallTeam.h"
#include "TennisTeam.h"

void Database::Create(SportsTeam::sport type)
{
    SportsTeam* holdTeam = nullptr;
    switch (type)
    {
        case SportsTeam::sport::BASKETBALL:
        {
            holdTeam = new BasketBallTeam();
            break;
        }
        case SportsTeam::sport::TENNIS:
        {
            holdTeam = new TennisTeam();
            break;
        }
    }
    holdTeam->Add(std::cout, std::cin);
    data.push_back(holdTeam);
}

void Database::DisplayAll()
{
    for (SportsTeam* team: data)
    {
        team->Display(std::cout);
    }
}

void Database::Display(const std::string& name)
{
    for (SportsTeam* team : data)
    {
        if (team->getName() == name)
        {
            team->Display(std::cout);
        }
    }
}

void Database::Display(SportsTeam::sport type)
{
    for (SportsTeam* team : data)
    {
        if (team->GetType() == type)
        {
            team->Display(std::cout);
        }
    }
}

Database::~Database()
{
    for (SportsTeam* team : data)
    {
        delete team;
    }
}