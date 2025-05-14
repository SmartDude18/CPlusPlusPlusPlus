#pragma once
#include <string>
#include <vector>;
#include "Player.h";

class DiceGameHandler
{
private:
    int dieSize, amountOfDice;
    int currentPlayer = -1, currentRound = 1, maxRounds;
    std::vector<Player> playerVector;
    bool gameFinish = false;
    std::string winner;
public: 
    DiceGameHandler(int numberOfPlayers, int dieSize, int amountOfDice, int amountOfRounds);
    int getCurrentRound();
    int getCurrentPlayer();
    std::vector<Player> getPlayerArray();
    bool isGameFinish();
    std::string getWinnerTxt();
    void nextTurn();
    void getWinners();
};