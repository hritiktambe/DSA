

/*

https://leetcode.com/problems/course-schedule-ii/

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        int n = numCourses;

        vector<vector<int>> g(n);
        int indeg[n];
        memset(indeg, 0, sizeof indeg);

        for (auto i : prerequisites)
        {
            g[i[1]].push_back(i[0]);
            indeg[i[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indeg[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while (!q.empty())
        {

            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                int t = q.front();
                q.pop();
                ans.push_back(t);
                for (int j : g[t])
                {
                    indeg[j]--;
                    if (indeg[j] == 0)
                        q.push(j);
                }
            }
        }
        if (ans.size() != n)
        {
            ans.clear();
        }

        return ans;
    }
};