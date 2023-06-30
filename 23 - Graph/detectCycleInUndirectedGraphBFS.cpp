#include <bits/stdc++.h>

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
    vector<int> vis(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            queue<pair<int, int>> q;
            vis[i] = 1;
            q.push({i, -1});

            while (!q.empty())
            {
                int node = q.front().first;
                int prev = q.front().second;
                q.pop();

                for (auto it : adj[node])
                {
                    if (!vis[it])
                    {
                        vis[it] = 1;
                        q.push({it, node});
                    }
                    else if (prev != it)
                        return "Yes";
                }
            }
        }
    }
    return "No";
}
