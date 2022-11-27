#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {

        bool rowzero = false, colzero = false;
        int n = matrix.size(), m = matrix[0].size();
        for (int j = 0; j < m; j++)
        {
            if (matrix[0][j] == 0)
            {
                rowzero = true;
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][0] == 0)
            {
                colzero = true;
                break;
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {

                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        //process only inner element
        for (int i = 1; i < n; i++)
        {

            for (int j = 1; j < m; j++)
            {

                if (matrix[i][0] == 0 or matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (rowzero)
        {

            for (int j = 0; j < m; j++)
            {
                matrix[0][j] = 0;
            }
        }
        if (colzero)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};