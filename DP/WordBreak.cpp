
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        unordered_map<string, int> m;
        for (auto i : wordDict)
            m[i]++;
        bool dp[n + 1];
        memset(dp, false, sizeof dp);
        dp[0] = true;

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j] and m[s.substr(j, i - j)])
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};