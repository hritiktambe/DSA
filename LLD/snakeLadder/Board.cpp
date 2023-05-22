#include <bits/stdc++.h>

using namespace std;

class Board
{
    vector<vector<Cell>> cells;
    public:
    int numOfCells ;
public:
    Board()
    {

    }

    Board(int numberOfCells,int numberOfSnakes,int numberOfLadders)
    {
        cells = vector<vector<Cell>>(numberOfCells, vector<Cell>(numberOfCells));
        numOfCells = numberOfCells;
        addSnakesAndLadders(numberOfSnakes, numberOfLadders);
    }

private:
    void addSnakesAndLadders(int noOfSnakes,int noOfLadders)
    {
        while(noOfSnakes>0)
        {
            int snakeHead = rand()%100;
            int snakeTail = rand()%100;

            if(snakeTail>snakeHead)
            continue;

            int x = snakeHead / (numOfCells);
            x = x % numOfCells;
            int y = snakeHead / (numOfCells);
            y = y % numOfCells;

            Jump snakeObj;

            snakeObj.start = snakeHead;
            snakeObj.end = snakeTail;

            cells[x][y].jump = snakeObj;

            noOfSnakes--;
        }
    }
}