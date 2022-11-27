/*

https://leetcode.com/problems/powx-n/

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1;
        long long nw = n;
        if (n < 0)
            nw = -1 * nw;
        while (nw > 0)
        {
            if (nw & 1)
            {
                ans = ans * x;
                nw--;
            }
            else
            {
                x = x * x;
                nw /= 2;
            }
        }
        if (n < 0)
            ans = 1 / ans;

        return ans;
    }
};