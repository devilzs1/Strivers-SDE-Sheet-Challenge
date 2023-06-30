
bool isCycle(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsVis)
{
    vis[node] = 1;
    dfsVis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (isCycle(it, adj, vis, dfsVis))
                return true;
        }
        else if (dfsVis[it])
            return true;
    }
    dfsVis[node] = 0;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // Write your code here.
    vector<int> adj[n + 1];
    for (auto it : edges)
    {
        adj[it.first].push_back(it.second);
    }
    vector<int> vis(n + 1), dfsVis(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (isCycle(i, adj, vis, dfsVis))
                return true;
        }
    }
    return false;
}