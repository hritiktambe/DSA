
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {

        if (s.length() < 2)
            return s;
        int n = s.length();
        bool dp[n][n];
        memset(dp, false, sizeof dp);
        int longestPalindromeStart = 0, longestPlaindromeSize = 1;
        for (int i = 0; i < n; i++)
            dp[i][i] = true;

        for (int start = n - 1; start >= 0; start--)
        {
            for (int end = start + 1; end < n; end++)
            {
                if (s[start] == s[end])
                {
                    if (end - start == 1 or dp[start + 1][end - 1])
                    {

                        dp[start][end] = true;

                        if (longestPlaindromeSize < end - start + 1)
                        {
                            longestPalindromeStart = start;
                            longestPlaindromeSize = end - start + 1;
                        }
                    }
                }
            }
        }
        string a = "";
        for (int i = longestPalindromeStart; i < longestPalindromeStart + longestPlaindromeSize; i++)
            a += s[i];

        return a;
    }
};