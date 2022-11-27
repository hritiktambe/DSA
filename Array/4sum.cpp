/*


*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        if (nums.size() < 4)
            return ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int target2 = target - nums[i];
            for (int j = i + 1; j < n; j++)
            {
                int left = j + 1, right = n - 1;
                int target3 = target2 - nums[j];
                while (left < right)
                {
                    int sum = nums[left] + nums[right];

                    if (sum < target3)
                    {
                        left++;
                    }
                    else if (sum > target3)
                        right--;
                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        int front = nums[left], back = nums[right];
                        while (left < right and front == nums[left])
                            left++;
                        while (left < right and back == nums[right])
                            right--;
                    }
                }

                while (j + 1 < n and nums[j] == nums[j + 1])
                    j++;
            }

            while (i + 1 < n and nums[i] == nums[i + 1])
                i++;
        }

        return ans;
    }
};