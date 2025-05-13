#include "Player.h";
#include <vector>;

Player::Player(int rollsPerTurn, int dieSize)
{
    //currentRollSet = new Die[rollsPerTurn];
    for (int i = 0; i < rollsPerTurn; i++)
    {
        Die holdDie(dieSize);
        currentRollSet.push_back(holdDie);
    }
}

int Player::getRollSetTotal()
{
    return rollSetTotal;
}

int Player::getTotalScore()
{
    return totalScore;
}

std::vector<Die> Player::getCurrentRollSet()
{
    return currentRollSet;
}

void Player::playTurn()
{
    rollSetTotal = 0;
    for (int i = 0; i < currentRollSet.size(); i++)
    {
        currentRollSet[i].rollDie();
        totalScore += currentRollSet[i].getRoll();
        rollSetTotal += currentRollSet[i].getRoll();
    }
}