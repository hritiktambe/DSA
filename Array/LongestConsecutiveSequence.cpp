/*
https://leetcode.com/problems/longest-consecutive-sequence/

*/


#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto i : nums)
            mp[i]++;
        int ans = 0;
        for (auto i : nums)
        {
            int count = 1, tmp = i;
            if (mp.find(tmp - 1) != mp.end())
                continue;
            while (mp.find(tmp + 1) != mp.end())
                tmp++, count++;

            ans = max(ans, count);
        }

        return ans;
    }
};