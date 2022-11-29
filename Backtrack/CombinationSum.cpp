
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> v;
        vector<int> a;
        combine(v, a, candidates, target, 0);

        return v;
    }

    void combine(vector<vector<int>> &v, vector<int> a, vector<int> &c, int target, int begin)
    {
        if (!target)
        {
            v.push_back(a);
            return;
        }

        for (int i = begin; i < c.size(); i++)
        {
            if (c[i] <= target)
            {
                a.push_back(c[i]);
                combine(v, a, c, target - c[i], i);
                a.pop_back();
            }
        }
    }
};