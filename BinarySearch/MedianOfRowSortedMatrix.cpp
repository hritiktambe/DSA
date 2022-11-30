//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        int n = R * C;
        int l = 1, r = 10000;

        while (l <= r)
        {   

            int mid = (l + r) >> 1;
            int count = 0;
            for (int i = 0; i < R; i++)
            {
                count += (upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin());
                //cout<<count<<endl;
            }

            if (count > n / 2)
                r = mid - 1;
            else if (count <= n / 2)
                l = mid + 1;
        }
        return l;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        cout << obj.median(matrix, r, c) << endl;
    }
    return 0;
}
// } Driver Code Ends