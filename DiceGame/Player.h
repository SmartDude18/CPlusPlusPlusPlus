#pragma once
#include <vector>
#include "Die.h";

class Player
{
private:
    std::vector<Die> currentRollSet;
    int totalScore = 0, rollSetTotal;
public:
    Player(int rollsPerTurn, int dieSize);
    int getTotalScore();
    std::vector<Die> getCurrentRollSet();
    int getRollSetTotal();
    void playTurn();
};