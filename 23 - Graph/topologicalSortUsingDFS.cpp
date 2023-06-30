#include <bits/stdc++.h>

void dfs(int par, vector<int> &vis, stack<int> &st, vector<int> adj[])
{

    vis[par] = 1;
    for (auto it : adj[par])
    {
        if (!vis[it])
        {
            dfs(it, vis, st, adj);
        }
    }
    st.push(par);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here

    vector<int> topo;
    stack<int> st;
    vector<int> adj[v + 1];
    for (auto it : edges)
    {
        int u = it[0], v = it[1];
        adj[u].push_back(v);
    }
    vector<int> vis(v);
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, st, adj);
        }
    }
    while (!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}