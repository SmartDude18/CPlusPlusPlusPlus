#include "DiceGameHandler.h";
#include <iostream>;

DiceGameHandler::DiceGameHandler(int numPlayers, int dieFaces, int numDice, int numRounds)
{
    dieSize = dieFaces;
    amountOfDice = numDice;
    for (int i = 0; i < numPlayers; i++)
    {
        Player holdPlayer(numDice, dieFaces);
        playerVector.push_back(holdPlayer);
    }
    currentRound = 1;
    currentPlayer = -1;
    maxRounds = numRounds;
}

int DiceGameHandler::getCurrentRound()
{
    return currentRound;
}

int DiceGameHandler::getCurrentPlayer()
{
    return currentPlayer;
}

std::vector<Player> DiceGameHandler::getPlayerArray()
{
    return playerVector;
}

bool DiceGameHandler::isGameFinish()
{
    return gameFinish;
}

std::string DiceGameHandler::getWinnerTxt()
{
    return winner;
}

void DiceGameHandler::nextTurn()
{
    if (gameFinish) { return; }
    currentPlayer++;
    if (currentPlayer == playerVector.size())
    {
        currentPlayer = 0;
        currentRound++;
    }
    if (currentRound > maxRounds)
    {
        currentRound = maxRounds;
        gameFinish = true;
        getWinners();
        return;
    }
    playerVector[currentPlayer].playTurn();
}

void DiceGameHandler::getWinners()
{
    std::vector<std::string> winnerList;
    int highestScore = 0;
    for (int i = 0; i < playerVector.size(); i++)
    { 
        if (playerVector[i].getTotalScore() > highestScore)
        {
            winnerList.clear();
            highestScore = playerVector[i].getTotalScore();
            winnerList.push_back("Player " + std::to_string(i + 1));
        }
        else if (playerVector[i].getTotalScore() == highestScore)
        {
            winnerList.push_back("Player " + std::to_string(i + 1));
        }
    }
    std::string winners = "";
    for (int i = 0; i < winnerList.size(); i++)
    {
        winners += winnerList[i];
        if (i != winnerList.size() - 1) {
            winners += ", ";
        }
    }
    winner = winners;
}