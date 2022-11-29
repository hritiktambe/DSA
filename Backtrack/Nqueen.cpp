/*

https://leetcode.com/problems/n-queens/

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> v;
        vector<string> g(n, string(n, '.'));

        nqueen(v, g, 0, n);

        return v;
    }

    void nqueen(vector<vector<string>> &v, vector<string> &g, int row, int n)
    {
        if (row == n)
        {
            v.push_back(g);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (isValid(row, col, g, n))
            {
                g[row][col] = 'Q';
                nqueen(v, g, row + 1, n);
                g[row][col] = '.';
            }
        }
    }

    bool isValid(int row, int col, vector<string> &g, int n)
    {
        //check col
        for (int i = 0; i < n; i++)
            if (g[i][col] == 'Q')
                return false;

        //check row
        for (int j = 0; j < n; j++)
            if (g[row][j] == 'Q')
                return false;

        //check 135
        for (int i = row, j = col; i >= 0 and j >= 0; i--, j--)
            if (g[i][j] == 'Q')
                return false;

        //check 45
        for (int i = row, j = col; i >= 0 and j < n; i--, j++)
            if (g[i][j] == 'Q')
                return false;

        return true;
    }
};