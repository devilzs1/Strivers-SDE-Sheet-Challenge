#include <bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    vector<int> adj[v + 1];
    vector<int> indegree(v + 1);
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        indegree[it[1]]++;
    }
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    return topo;
}