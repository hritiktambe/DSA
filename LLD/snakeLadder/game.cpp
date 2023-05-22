#include <bits/stdc++.h>
#include "Board.cpp"

using namespace std;

class Game
{
    Board board;
    Dice dice;
    deque<Player> players;
    Player winner;
public:
    Game()
    {
        InitializeGame();
    }
    
private :
    void InitializeGame()
    {   
        //board input Board(no. of cells,no. of snakes,no of ladder)
        board = Board(10,5,4);
        dice = Dice(1);
        //winner is initially -1;
        addPlayers();
    }

    void addPlayers()
    {
        Player p1("p1",0);
        Player p2("p2",0);

        players.push_back(p1);
        players.push_back(p2);
    }

public:
    void play()
    {
        while(winner.id==-1)
        {
            //check whose trun
            Player playerTurn = findPlayerTurn();

            //roll dice
            int diceNum = dice.RollDice(); 

            //new position
            int playerNewPosition = playerTurn.currentPosition + diceNum;

            //check if at position there is ladder or snake
            playerNewPosition = jumpCheck(playerNewPosition);

            playerTurn.currentPosition = playerNewPosition;

            if (playerNewPosition >= board.numOfCells * board.numOfCells-1)
            {
                winner.id = playerTurn.id;
            }
        }

        cout<<"Winner is :"<<winner.id<<endl;
    }
};