// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{

    int mx[4] = {-1, 1, 0, 0}, my[4] = {0, 0, -1, 1}; //UDLR
    string t = "UDLR";

    void dfs(int x, int y, int n, string &s, vector<vector<bool>> &vis, vector<string> &ans, vector<vector<int>> &m)
    {
        //cout<<x<<" "<<y<<endl;
        if (m[x][y] == 1 and x == n - 1 and y == n - 1)
        {

            ans.push_back(s);
            return;
        }

        vis[x][y] = true;

        for (int i = 0; i < 4; i++)
        {

            int nx = mx[i] + x;
            int ny = my[i] + y;
            //cout<<nx<<" "<<ny<<" "<<t[i]<<endl;
            if (nx >= 0 and nx < n and ny >= 0 and ny < n and m[nx][ny] == 1 and !vis[nx][ny])
            {
                //cout<<"inside "<<nx<<" "<<ny<<endl;
                s.push_back(t[i]);
                dfs(nx, ny, n, s, vis, ans, m);
                s.pop_back();
            }
        }

        vis[x][y] = false;
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {

        vector<string> ans;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        string s = "";

        if (m[0][0] == 1)
            dfs(0, 0, n, s, vis, ans, m);

        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends