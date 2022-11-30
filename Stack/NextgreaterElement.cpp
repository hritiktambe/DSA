
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp;
        stack<int> st;

        for (auto i : nums2)
        {
            if (st.empty())
            {
                st.push(i);
                continue;
            }
            while (!st.empty() and i > st.top())
            {
                mp[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty())
        {
            mp[st.top()] = -1;
            st.pop();
        }

        for (int i = 0; i < nums1.size(); i++)
        {
            nums1[i] = mp[nums1[i]];
        }

        return nums1;
    }
};