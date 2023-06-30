#include <bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // Write your code here.

    vector<pair<int, int>> adj[vertices];
    for (auto it : vec)
    {
        int u = it[0], v = it[1], wt = it[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;
    pq.push({source, 0});
    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();
        for (auto it : adj[node.first])
        {
            if (dist[it.first] > dist[node.first] + it.second)
            {
                dist[it.first] = dist[node.first] + it.second;
                pq.push({it.first, dist[it.first]});
            }
        }
    }
    return dist;
}
