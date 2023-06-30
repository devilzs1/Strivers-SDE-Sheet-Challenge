#include <bits/stdc++.h>
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    // Write your code here.
    const int maxi = 1000000000;
    vector<int> dist(n + 1, maxi);
    dist[src] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (auto it : edges)
        {
            int u = it[0], v = it[1], wt = it[2];
            if (dist[u] != maxi && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }
    bool neg = false;
    for (auto it : edges)
    {
        int u = it[0], v = it[1], wt = it[2];
        if (dist[u] != maxi && dist[u] + wt < dist[v])
        {
            neg = true;
        }
    }
    return neg ? -1 : dist[dest];
}