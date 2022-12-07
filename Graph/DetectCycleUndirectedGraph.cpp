//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in an undirected graph.

    bool helper(int x, int parent, vector<bool> &vis, vector<int> g[])
    {

        vis[x] = true;

        for (int i = 0; i < g[x].size(); i++)
        {

            if (!vis[g[x][i]])
            {

                if (helper(g[x][i], x, vis, g))
                    return true;
            }
            else
            {
                if (g[x][i] != parent)
                    return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {

        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++)
        {

            if (!vis[i] and helper(i, i, vis, adj))
                return true;
        }

        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends