/*

https://leetcode.com/problems/remove-duplicates-from-sorted-array/

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        int i = 0, n = nums.size();
        for (int j = 0; j < n; j++)
        {
            if (nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};