#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t, n, k, x, y;

    cin >> t;
    while (t--)
    {
        cin >> x >> y; // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2; // Take both the string as input

        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends

// function to find longest common subsequence

int lcs(int x, int y, string s1, string s2)
{

    int dp[x + 1][y + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 1; i < x + 1; i++)
    {
        for (int j = 1; j < y + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[x][y];
}

#if 0
void lcs(char* X, char* Y, int m, int n)
{
    int L[m + 1][n + 1];
 
    /* Following steps build L[m+1][n+1] in bottom up
      fashion. Note that L[i][j] contains length of LCS of
      X[0..i-1] and Y[0..j-1] */
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
 
    // Following code is used to print LCS
    int index = L[m][n];
 
    // Create a character array to store the lcs string
    char lcs[index + 1];
    lcs[index] = '\0'; // Set the terminating character
 
    // Start from the right-most-bottom-most corner and
    // one by one store characters in lcs[]
    int i = m, j = n;
    while (i > 0 && j > 0) {
        // If current character in X[] and Y are same, then
        // current character is part of LCS
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1]
                = X[i - 1]; // Put current character in result
            i--;
            j--;
            index--; // reduce values of i, j and index
        }
 
        // If not same, then find the larger of two and
        // go in the direction of larger value
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }
 
    // Print the lcs
    cout << "LCS of " << X << " and " << Y << " is " << lcs;
}
#endif