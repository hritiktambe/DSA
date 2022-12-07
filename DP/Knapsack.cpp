#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{

    int dp[n + 1][W + 1];

    memset(dp, 0, sizeof dp);

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (j >= wt[i - 1])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wt[i - 1]] + val[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][W];
}
