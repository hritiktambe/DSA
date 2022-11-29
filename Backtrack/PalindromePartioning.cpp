
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {

        vector<vector<string>> ans;
        vector<string> v;
        helper(0, s, v, ans);

        return ans;
    }

    void helper(int start, string &s, vector<string> &v, vector<vector<string>> &ans)
    {

        if (start >= s.size())
        {

            ans.push_back(v);
            return;
        }

        string temp = "";

        for (int i = start; i < s.size(); i++)
        {

            temp += s[i];
            if (isPalindrome(temp))
            {

                v.push_back(temp);
                helper(i + 1, s, v, ans);
                v.pop_back();
            }
        }
    }

    bool isPalindrome(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());

        return t == s;
    }
};