#include <bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int> adj[vertex];
    for (auto it : edges)
    {
        int u = it.first, v = it.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < vertex; i++)
    {
        sort(begin(adj[i]), end(adj[i]));
    }
    vector<int> vis(vertex, 0);
    vector<int> trav;
    for (int i = 0; i < vertex; i++)
    {
        if (!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                trav.push_back(node);
                for (auto it : adj[node])
                {
                    if (!vis[it])
                    {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
        }
    }
    return trav;
}