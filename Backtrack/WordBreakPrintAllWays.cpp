//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void helper(int in, vector<string> &t, string &s, unordered_map<string, int> &mp, vector<string> &ans)
    {

        if (in >= s.size())
        {

            string a = t[0];
            for (int i = 1; i < t.size(); i++)
            {
                a += " " + t[i];
            }

            ans.push_back(a);

            return;
        }

        string temp = "";

        for (int i = in; i < s.size(); i++)
        {
            temp += s[i];
            if (mp.find(temp) != mp.end())
            {
                t.push_back(temp);
                helper(i + 1, t, s, mp, ans);
                t.pop_back();
            }
        }
    }

    vector<string> wordBreak(int n, vector<string> &dict, string s)
    {
        vector<string> ans;
        vector<string> t;
        unordered_map<string, int> mp;

        for (auto i : dict)
            mp[i]++;

        helper(0, t, s, mp, ans);

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        vector<string> dict;
        string s;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            dict.push_back(s);
        }
        cin >> s;

        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if (ans.size() == 0)
            cout << "Empty\n";
        else
        {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
                cout << "(" << ans[i] << ")";
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends