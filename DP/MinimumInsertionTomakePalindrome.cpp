
#include<bits/stdc++.h>
using namespace std;

class Solution  
{
public:
    int minInsertions(string s)
    {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));

        return cal(s, 0, s.length() - 1, dp);
    }

    int cal(string &s, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = s[i] == s[j] ? cal(s, i + 1, j - 1, dp) : 1 + min(cal(s, i, j - 1, dp), cal(s, i + 1, j, dp));
    }
};