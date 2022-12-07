
/*

https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> countDistinct(int A[], int n, int k)
    {

        int j = 0, count = 0;
        unordered_map<int, int> mp;

        for (j = 0; j < k; j++)
        {
            if (mp.find(A[j]) == mp.end())
            {
                mp[A[j]]++;
                count++;
                continue;
            }
            mp[A[j]]++;
        }
        int i = 0;
        vector<int> ans;
        ans.push_back(count);
        for (j = k; j < n; j++)
        {
            mp[A[i]]--;
            if (mp[A[i]] <= 0)
                count--;

            i++;
            if (mp[A[j]] <= 0 or mp.find(A[j]) == mp.end())
            {
                mp[A[j]]++;
                count++;
            }
            else
                mp[A[j]]++;
            ans.push_back(count);
        }

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

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        vector<int> result = obj.countDistinct(a, n, k);
        for (int i : result)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends