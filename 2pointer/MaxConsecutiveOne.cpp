/*

https://leetcode.com/problems/max-consecutive-ones/

*/

#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {

        int count = 0, maxi = 0, n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 1)
                count = 0;
            else
                count++;

            maxi = max(maxi, count);
        }

        return maxi;
    }
};