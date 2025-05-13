#include "DiceGameHandler.h";
#include <iostream>;
/*
private int dieSize, amountOfDice;
    private int currentPlayer = -1, currentRound = 1, maxRounds;
    private Player[] playerArray;
    private boolean gameFinish = false;
    private String winner;


    //Constructors
    public DiceGame(int numberOfPlayers, int dieSize, int amountOfDice, int amountOfRounds)
    {
        this.dieSize = dieSize;
        this.amountOfDice = amountOfDice;
        playerArray = new Player[numberOfPlayers];
        currentRound = 1;
        currentPlayer = -1;
        this.maxRounds = amountOfRounds;
        initGame();
    }

    //Getters and setters
    public int getCurrentRound()
    {
        return currentRound;
    }
    public int getCurrentPlayer()
    {
        return currentPlayer;
    }
    public Player[] getPlayerArray()
    {
        return playerArray;
    }
    public boolean isGameFinish()
    {
        return gameFinish;
    }
    public String getWinnerTxt()
    {
        return winner;
    }
    //other Func
    private void initGame()
    {
        for(int i = 0; i < playerArray.length; i++)
        {
            playerArray[i] = new Player(amountOfDice,dieSize);
        }
    }

    public void nextTurn()
    {
        if(gameFinish){return;}
        currentPlayer++;
        if(currentPlayer == playerArray.length)
        {
            currentPlayer = 0;
            currentRound++;
        }
        if(currentRound > maxRounds)
        {
            currentRound = maxRounds;
            gameFinish = true;
            getWinner();
            return;
        }
        playerArray[currentPlayer].playTurn();
    }

    private void getWinner()
    {
        String[] winnerList = new String[playerArray.length];
        int highestScore = 0;
        int currentIndex = 0;
        for(int i = 0; i < playerArray.length; i++)
        {
            if(playerArray[i].getTotalScore() > highestScore)
            {
                winnerList = new String[playerArray.length];
                currentIndex = 0;
                highestScore = playerArray[i].getTotalScore();
                winnerList[currentIndex] = "Player " + (i +1);
            }
            else if(playerArray[i].getTotalScore() == highestScore)
            {
                currentIndex++;
                winnerList[currentIndex] = "Player " + (i +1);
            }
        }
        winner = new String();
        for(int i = 0; i < currentIndex + 1; i++)
        {
            winner += winnerList[i];
            if(i != currentIndex){
                winner += ", ";
            }
        }
    }



class DiceGameHandler
{
private:
    int dieSize, amountOfDice;
    int currentPlayer = -1, currentRound = 1, maxRounds;
    std::vector<Player> playerArray;
    bool gameFinish = false;
    std::string winner;
public:
    DiceGameHandler(int numberOfPlayers, int dieSize, int amountOfDice, int amountOfRounds);
    int getCurrentRound();
    int getCurrentPlayer();
    std::vector<Player> getPlayerArray();
    bool isGameFinish();
    std::string getWinnerTxt();
    void initGame();
    void nextTurn();
    void getWinner();
};
*/


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