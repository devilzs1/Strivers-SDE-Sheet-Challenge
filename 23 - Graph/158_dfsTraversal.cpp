
void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &temp)
{
    vis[node] = 1;
    temp.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, temp);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int> adj[V];
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> vis(V);
    vector<vector<int>> dfsearch;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            vector<int> temp;
            dfs(i, adj, vis, temp);
            dfsearch.push_back(temp);
        }
    }
    return dfsearch;
}