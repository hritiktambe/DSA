

/*
https://leetcode.com/problems/search-in-rotated-sorted-array/

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (!nums.size())
            return -1;
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[r])
                r = mid;
            else
                l = mid + 1;
        }
        int rot = l;
        l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2, rm;
            rm = (mid + rot) % nums.size();
            if (nums[rm] == target)
                return rm;
            if (nums[rm] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};