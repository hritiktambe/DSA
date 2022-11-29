
/*

https://leetcode.com/problems/palindrome-partitioning-ii/

*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int helper(int index, string s, vector<int> &dp)
    {

        if (index >= s.size())
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int mincut = INT_MAX / 10;
        string temp = "";
        for (int i = index; i < s.size(); i++)
        {

            temp += s[i];
            if (isPalindrome(temp))
            {
                mincut = min(mincut, 1 + helper(i + 1, s, dp));
            }
        }

        return dp[index] = mincut;
    }

    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n, -1);

        return helper(0, s, dp) - 1;
    }

    bool isPalindrome(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());

        return t == s;
    }
};