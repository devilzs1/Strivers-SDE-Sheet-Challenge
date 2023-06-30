#include <bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    vector<pair<pair<int, int>, int>> mst;
    vector<pair<int, int>> adj[n + 1];
    for (auto it : g)
    {
        int u = it.first.first, v = it.first.second, wt = it.second;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    vector<int> vis(n + 1);
    priority_queue<pair<pair<int, int>, int>,
                   vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>>pq;
    pq.push({{0, 1}, -1});
    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();
        int wt = node.first.first, u = node.first.second, par = node.second;

        if (vis[u] == 1)
            continue;
        vis[u] = 1;
        if (par != -1)
            mst.push_back({{u, par}, wt});
        for (auto it : adj[u])
        {
            if (!vis[it.first])
            {
                pq.push({{it.second, it.first}, u});
            }
        }
    }
    return mst;
}
