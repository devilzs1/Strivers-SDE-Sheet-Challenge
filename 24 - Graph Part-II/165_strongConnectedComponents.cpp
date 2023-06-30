#include <bits/stdc++.h>

// *kosaraju algorithm - Time complexity : O(V + E) 
void dfs(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, st, adj);
        }
    }
    st.push(node);
}
void storedfs(int node, vector<int> &vis, vector<int> &temp,
              vector<vector<int>> &conn, vector<int> tadj[])
{
    vis[node] = 1;
    temp.push_back(node);
    for (auto it : tadj[node])
    {
        if (!vis[it])
        {
            storedfs(it, vis, temp, conn, tadj);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> adj[n];
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
    }
    stack<int> st;
    vector<int> vis(n);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, st, adj);
        }
    }
    vector<int> tadj[n];
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            tadj[it].push_back(i);
        }
    }
    vector<vector<int>> conn;
    vector<int> temp;
    while (!st.empty())
    {
        int x = st.top();
        st.pop();
        if (!vis[x])
        {
            storedfs(x, vis, temp, conn, tadj);
            conn.push_back(temp);
            temp.clear();
        }
    }
    return conn;
}