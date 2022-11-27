/*

https://leetcode.com/problems/trapping-rain-water/


here for a place to hold water there should be a building on left as well as right
how much water the place can hold depends on the mx height on the left and max height on the right
out of them the smallest minus the height of place

min(maxofleft,maxofright)-a[i]

here 2 pointer approach is used l=0 , r= n-1 in which we make sure when we are the place that suppose 
height[l]<=height[r] this ensures that for the place to hold water there is atleast a block on the right greater than equal to 
height on the left if it is greater than leftmax than it will hold no water


*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int l = 0, r = n - 1, leftmax = 0, rightmax = 0;
        int ans = 0;

        while (l <= r)
        {
            if (height[l] <= height[r]) //this will make sure that there is atleast a height that is equal to one where we are standing that is going to hold the water
            {
                if (height[l] > leftmax) //if this is true that the pos is not going to hold the water
                    leftmax = height[l];
                else
                    ans += (leftmax - height[l]);

                l++;
            }
            else
            {
                if (height[r] > rightmax)
                    rightmax = height[r];
                else
                    ans += (rightmax - height[r]);

                r--;
            }
        }

        return ans;
    }
};