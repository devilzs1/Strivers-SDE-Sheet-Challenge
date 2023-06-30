
bool isCycle(int node, int par, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (isCycle(it, node, adj, vis))
                return true;
        }
        else if (it != par)
            return true;
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // Write your code here.
    vector<int> adj[n + 1];
    for (auto it : edges)
    {
        int u = it[0], v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    string cycle = "No";
    vector<int> vis(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (isCycle(i, i, adj, vis))
            {
                cycle = "Yes";
                break;
            }
        }
    }
    return cycle;
}
