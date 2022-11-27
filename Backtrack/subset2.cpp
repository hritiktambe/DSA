/*
https://leetcode.com/problems/subsets-ii/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        vector<int> a;
        v.push_back(a);
        sub(v, a, nums, 0);
        return v;
    }

    void sub(vector<vector<int>> &v, vector<int> a, vector<int> nums, int begin)
    {
        if (begin == nums.size())
            return;
        for (int i = begin; i < nums.size(); i++)
        {
            if ((i == begin) or nums[i] != nums[i - 1])
            {
                // cout<<"i1 "<<i<<endl;
                a.push_back(nums[i]);
                sub(v, a, nums, i + 1);
                v.push_back(a);
                a.pop_back();
            }
        }
    }
};