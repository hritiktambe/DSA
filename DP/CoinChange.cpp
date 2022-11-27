
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();

        int dp[amount + 1];
        for (int i = 0; i < amount + 1; i++)
            dp[i] = INT_MAX;

        dp[0] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = coins[i]; j < amount + 1; j++)
            {
                if (dp[j - coins[i]] != INT_MAX)
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }

        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};