

/*
https://leetcode.com/problems/longest-increasing-subsequence/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lis(int index, int prev, int n, vector<int> &nums, vector<vector<int>> &dp)
    {

        if (index > n)
            return 0;

        if (dp[index][prev] != -1)
            return dp[index][prev];

        int len = lis(index + 1, prev, n, nums, dp); //not take

        if (prev == 0 or nums[index - 1] > nums[prev - 1])
            len = max(len, 1 + lis(index + 1, index, n, nums, dp));

        return dp[index][prev] = len;
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return lis(1, 0, n, nums, dp);
    }
};