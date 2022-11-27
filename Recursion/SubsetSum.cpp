//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void helper(int in, int sum, vector<int> &v, vector<int> &a, int n)
    {
        if (in >= n)
        {
            v.push_back(sum);
            return;
        }

        helper(in + 1, sum, v, a, n);
        helper(in + 1, sum + a[in], v, a, n);

        return;
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {

        vector<int> v;

        helper(0, 0, v, arr, N);

        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans)
        {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends