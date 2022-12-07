
#include <bits/stdc++.h>
using namespace std;
    
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int dp[n + 1][k + 1];
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < k + 1; i++)
            dp[0][i] = 0;
        for (int i = 0; i < n + 1; i++)
            dp[i][0] = 0;
        for (int i = 1; i < n + 1; i++)
            dp[i][1] = 1;
        for (int i = 1; i < k + 1; i++)
            dp[1][i] = i;

        for (int i = 2; i < n + 1; i++)
        {
            for (int j = 2; j < k + 1; j++)
            {
                int mn = INT_MAX;
                for (int z = 1; z <= j; z++)
                    mn = min(mn, 1 + max(dp[i - 1][z - 1], dp[i][j - z]));

                dp[i][j] = mn;
            }
        }
        // for(int i=0;i<n+1;i++)
        // {
        //     for(int j=0;j<k+1;j++)
        //     cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }

        cout << dp[n][k] << endl;
    }
}