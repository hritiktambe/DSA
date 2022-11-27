/*
https://leetcode.com/problems/two-sum/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        unordered_map<int, int> mp;
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (mp.find(target - nums[i]) != mp.end())
            {
                ans.push_back(mp[target - nums[i]]);
                ans.push_back(i);
                break;
            }
            else
            {
                mp[nums[i]] = i;
            }
        }

        return ans;
    }
};