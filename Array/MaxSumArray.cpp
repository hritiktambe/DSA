#include <bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/maximum-subarray/
*/

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {

        int mx = nums[0];

        if (nums.size() == 1)
            return mx;

        for (int i = 1; i < nums.size(); i++)
        {

            nums[i] = max(nums[i], nums[i] + nums[i - 1]);

            mx = max(mx, nums[i]);
        }

        return mx;
    }
};