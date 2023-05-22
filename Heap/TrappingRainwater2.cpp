/*

https://leetcode.com/problems/trapping-rain-water-ii/submissions/
https://www.youtube.com/watch?v=fywyCy6Fyoo
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

    int mx[4] = {0, 1, 0, -1}, my[4] = {1, 0, -1, 0};

private:
    class Block
    {
    public:
        int r, c, h;

        Block(int r, int c, int h) : r(r), c(c), h(h) {}
    };

    //comparator for min heap
    struct compare
    {

        bool operator()(Block b1, Block b2)
        {

            return b1.h > b2.h;
        }
    };

public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int n = heightMap.size(), m = heightMap[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        priority_queue<Block, vector<Block>, compare> mn_heap;

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {

                if (i == 0 or j == 0 or j == m - 1 or i == n - 1)
                {
                    vis[i][j] = true;
                    Block b(i, j, heightMap[i][j]);

                    mn_heap.push(b);
                }
            }
        }

        int water = 0;

        while (!mn_heap.empty())
        {

            Block t = mn_heap.top();
            mn_heap.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = t.r + mx[i];
                int ny = t.c + my[i];

                if (nx >= 0 and nx < n and ny >= 0 and ny < m and !vis[nx][ny])
                {

                    water += max(0, t.h - heightMap[nx][ny]);

                    if (heightMap[nx][ny] >= t.h)
                    {
                        Block b(nx, ny, heightMap[nx][ny]);
                        mn_heap.push(b);
                    }
                    else
                    {
                        Block b(nx, ny, t.h);
                        mn_heap.push(b);
                    }
                    vis[nx][ny] = true;
                }
            }
        }

        return water;
    }
};