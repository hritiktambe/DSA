
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int x, int color[], vector<vector<int>> &graph)
    {

        for (int i : graph[x])
        {

            if (color[i] == 0)
            {
                color[i] = color[x] == 1 ? 2 : 1;
                if (dfs(i, color, graph))
                    return true;
            }
            else if (color[i] != color[x])
                continue;
            else if (color[i] == color[x])
                return true;
        }

        return false;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();

        int color[n];
        memset(color, 0, sizeof color);

        for (int i = 0; i < n; i++)
        {

            if (color[i] == 0)
            {
                color[i] = 1;
                if (dfs(i, color, graph))
                    return false;
            }
        }

        return true;
    }
};