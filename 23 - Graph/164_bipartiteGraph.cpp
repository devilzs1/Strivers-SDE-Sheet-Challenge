#include <bits/stdc++.h>

bool bipartite(int par, vector<int> adj[], vector<int> &color)
{
    queue<int> q;
    q.push(par);
    color[par] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
                return false;
        }
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges)
{
    // Write your code here.
    int n = edges.size();
    vector<int> adj[n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (edges[i][j] == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!bipartite(i, adj, color))
                return false;
        }
    }
    return true;
}