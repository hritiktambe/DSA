

/*

https://leetcode.com/problems/network-delay-time/

Time complexity :- ElogV
E-edges,V-vertices

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {

        vector<vector<pair<int, int>>> g(n + 1, vector<pair<int, int>>(n + 1));

        for (auto i : times)
        {
            g[i[0]].push_back({i[1], i[2]});
        }

        vector<int> d(n + 1, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_pq;
        d[k] = 0;
        min_pq.push({0, k});

        while (!min_pq.empty())
        {
            int u = min_pq.top().second;
            min_pq.pop();

            for (auto i : g[u])
            {
                if (d[i.first] > d[u] + i.second)
                {
                    d[i.first] = d[u] + i.second;
                    min_pq.push({d[i.first], i.first});
                }
            }
        }

        int ans = *max_element(d.begin() + 1, d.end());


        return ans == INT_MAX ? -1 : ans;
    }
};