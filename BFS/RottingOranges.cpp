/*

https://leetcode.com/problems/rotting-oranges/

*/

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution
{

    int mx[4] = {-1, 1, 0, 0}, my[4] = {0, 0, -1, 1}; //UDLR

public:
    int orangesRotting(vector<vector<int>> &grid)
    {

        int count = 0, n = grid.size(), m = grid[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {

                if (grid[i][j] != 0)
                    count++;
                if (grid[i][j] == 2)
                {

                    q.push({i, j});
                    count--;
                }
            }
        }

        int ans = -1;
        while (!q.empty())
        {

            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {

                pair<int, int> p;
                p = q.front();
                q.pop();

                for (int j = 0; j < 4; j++)
                {

                    int nx = p.first + mx[j];
                    int ny = p.second + my[j];

                    if (nx >= 0 and nx < n and ny >= 0 and ny < m and grid[nx][ny] == 1)
                    {

                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        count--;
                    }
                }
            }
            ans++;
        }

        ans = ans == -1 ? 0 : ans;

        return count == 0 ? ans : -1;
    }
};