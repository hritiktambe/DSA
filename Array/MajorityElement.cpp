/*

https://leetcode.com/problems/majority-element/


*/

#include <bits/stdc++.h>
using namespace std;

#if 0
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        int count = 0, cand = 0;

        for (auto i : nums)
        {
            if (count == 0)
            {
                cand = i;
            }
            if (i == cand)
                count++;
            else
                count--;
        }

        return cand;
    }
};

#endif

/*

https://leetcode.com/problems/majority-element-ii/

*/

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> v;
        if (!nums.size())
            return v;
        int cand1 = 0, cand2 = 0, count1 = 0, count2 = 0;

        for (auto i : nums)
        {
            if (cand1 == i)
                count1++;
            else if (cand2 == i)
                count2++;
            else if (!count1)
                cand1 = i, count1 = 1;
            else if (!count2)
                cand2 = i, count2 = 1;
            else
                count1--, count2--;
        }
        // cout<<cand1<<" "<<cand2<<endl;
        count1 = 0, count2 = 0;
        for (auto i : nums)
        {
            if (cand1 == i)
                count1++;
            else if (cand2 == i)
                count2++;
            if (count1 > (nums.size() / 3))
                v.push_back(cand1), count1 = 0, cand1 = -1;
            if (count2 > (nums.size() / 3))
                v.push_back(cand2), count2 = 0, cand2 = -1;
        }

        return v;
    }
};