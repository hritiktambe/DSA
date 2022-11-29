// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9

// } Driver Code Ends
class Solution
{
public:
    bool isSafe(int l, int row, int col, int grid[N][N])
    {
        //row check
        for (int i = 0; i < 9; i++)
        {
            if (grid[row][i] == l)
                return false;
        }

        //col check
        for (int i = 0; i < 9; i++)
        {
            if (grid[i][col] == l)
                return false;
        }

        //block check
        for (int i = 3 * (row / 3); i <= 3 * (row / 3) + 2; i++)
        {
            for (int j = 3 * (col / 3); j <= 3 * (col / 3) + 2; j++)
            {
                if (grid[i][j] == l)
                    return false;
            }
        }

        return true;
    }

    bool solve(int row, int col, int grid[N][N])
    {

        if (row == 8 and col == 9)
        {
            return true;
        }
        if (col == 9)
        {
            col = 0;
            row++;
        }

        if (grid[row][col] == 0)
        {
            for (int l = 1; l < 10; l++)
            {

                if (isSafe(l, row, col, grid))
                {
                    grid[row][col] = l;
                    if (solve(row, col + 1, grid))
                        return true;

                    grid[row][col] = 0;
                }
            }
        }
        else if (solve(row, col + 1, grid))
            return true;

        return false;
    }
    bool SolveSudoku(int grid[N][N])
    {
        return solve(0, 0, grid);
    }

    //Function to print grids of the Sudoku.
    void printGrid(int grid[N][N])
    {
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int grid[N][N];

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> grid[i][j];

        Solution ob;

        if (ob.SolveSudoku(grid) == true)
            ob.printGrid(grid);
        else
            cout << "No solution exists";

        cout << endl;
    }

    return 0;
} // } Driver Code Ends