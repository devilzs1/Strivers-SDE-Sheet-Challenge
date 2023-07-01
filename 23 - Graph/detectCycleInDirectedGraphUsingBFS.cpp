// Using Kahn algorithm
#include <bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // Write your code here.
    vector<int> adj[n + 1];
    vector<int> indeg(n + 1);
    for (auto it : edges)
    {
        adj[it.first].push_back(it.second);
        indeg[it.second]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }
    int count = 0;
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        count++;
        for (auto it : adj[node])
        {
            indeg[it]--;
            if (indeg[it] == 0)
                q.push(it);
        }
    }
    return count != n;
}