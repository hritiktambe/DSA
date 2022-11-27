
/*

https://leetcode.com/problems/reverse-pairs/

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int merge(vector<int> &nums, vector<int> &temp, int left, int mid, int right)
    {
        int revPairs = 0;
        int j = mid, k = left;

        for (int i = left; i < mid; i++)
        {
            while (j <= right and nums[i] > 2LL * nums[j])
                j++;

            revPairs += j - mid;
        }

        int i = left;
        j = mid;

        while (i < mid and j <= right)
        {
            if (nums[i] <= nums[j])
            {
                temp[k++] = nums[i++];
            }
            else
            {
                temp[k++] = nums[j++];
            }
        }

        while (i < mid)
            temp[k++] = nums[i++];

        while (j <= right)
            temp[k++] = nums[j++];

        for (int i = left; i <= right; i++)
            nums[i] = temp[i];

        return revPairs;
    }

    int merge_sort(vector<int> &nums, vector<int> &temp, int left, int right)
    {

        int revPairs = 0;
        if (left < right)
        {
            int mid = left + (right - left) / 2;

            revPairs += merge_sort(nums, temp, left, mid);
            revPairs += merge_sort(nums, temp, mid + 1, right);

            revPairs += merge(nums, temp, left, mid + 1, right);
        }

        return revPairs;
    }

    int reversePairs(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> temp(n, 0);

        int ans = merge_sort(nums, temp, 0, n - 1);
        // for(auto i:nums)
        //     cout<<i<<" ";

        return ans;
    }
};