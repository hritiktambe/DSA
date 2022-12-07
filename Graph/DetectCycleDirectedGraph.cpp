
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in a directed graph.

    bool isCyclic(int V, vector<int> adj[])
    {
        int color[V];
        memset(color, 0, sizeof color);

        for (int i = 0; i < V; i++)
        {
            if (color[i] == 0 and dfs(i, adj, color))
                return true;
        }

        return false;
    }

    bool dfs(int x, vector<int> adj[], int color[])
    {
        color[x] = 1;
        for (int i = 0; i < adj[x].size(); i++)
        {
            if (color[adj[x][i]] == 2)
                continue;
            if (color[adj[x][i]] == 1)
                return true;

            if (color[adj[x][i]] == 0 and dfs(adj[x][i], adj, color))
                return true;
        }
        color[x] = 2;
        return false;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends