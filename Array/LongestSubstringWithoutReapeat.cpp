
/*

https://leetcode.com/problems/longest-substring-without-repeating-characters/


*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        int l = 0, r = 0, n = s.size();

        unordered_map<int, int> mp;
        int ans = 0;
        while (r < n)
        {

            if (mp.find(s[r]) != mp.end())
                l = max(l, mp[s[r]] + 1);

            ans = max(ans, r - l + 1);
            mp[s[r]] = r;
            r++;
        }

        return ans;
    }
};