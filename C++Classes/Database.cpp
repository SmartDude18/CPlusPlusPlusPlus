#include <fstream>
#include <string>
#include <vector>
#include "Database.h"
#include "SportsTeam.h"
#include "BasketBallTeam.h"
#include "TennisTeam.h"

void Database::Create(SportsTeam::sport type)
{
    std::ofstream myfile("dataBase.txt", std::ios::app);
    if (myfile.is_open())
    {
        SportsTeam* holdVectorTeam = nullptr;
        switch (type)
        {
        case SportsTeam::sport::BASKETBALL:
        {
            BasketBallTeam* holdTeam = new BasketBallTeam();
            holdTeam->Add(std::cout, std::cin);
            holdVectorTeam = holdTeam;
            myfile << *holdTeam << "\n";
            break;
        }
        case SportsTeam::sport::TENNIS:
        {
            TennisTeam* holdTeam = new TennisTeam();
            holdTeam = new TennisTeam();
            holdTeam->Add(std::cout, std::cin);
            holdVectorTeam = holdTeam;
            myfile << *holdTeam << "\n";
            break;
        }
        }
        data.push_back(holdVectorTeam);
        myfile.close();
    } 
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

Database::Database()
{
    std::string line, holdLineSection = "";
    std::vector<std::string> holdComponents;
    bool readSection = false;
    std::ifstream myfile("dataBase.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            holdComponents.clear();
            for (char c : line)
            {
                if (c == ':')
                {
                    readSection = true;
                    continue;
                }
                else if (c == ';')
                {
                    readSection = false;
                    holdComponents.push_back(holdLineSection);
                    holdLineSection = "";
                    continue;
                }
                if (readSection)
                {
                    holdLineSection += c;
                }
            }
            if (holdComponents[0] == "TennisTeam")
            {
                data.push_back(new TennisTeam(holdComponents[1], std::stoi(holdComponents[2])));
            }
            else if (holdComponents[0] == "BasketBallTeam")
            {
                data.push_back(new BasketBallTeam(holdComponents[1], std::stoi(holdComponents[2])));
            }
        }
        myfile.close();
    }
}