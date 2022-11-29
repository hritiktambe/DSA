/*

https://leetcode.com/problems/permutation-sequence/

Approach :- suppose n =4 and k=17 kth permutation of 1,2,3,4 will be 3,4,1,2

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {

        int fact = 1;
        vector<int> nums;
        for (int i = 1; i < n; i++)
        {

            fact *= i;
            nums.push_back(i);
        }

        nums.push_back(n);
        k--;
        string ans = "";

        while (true)
        {
            ans += to_string(nums[k / fact]);

            nums.erase(nums.begin() + k / fact);

            if (nums.size() == 0)
                break;

            k = k % fact;

            fact /= nums.size();
        }

        return ans;
    }
};