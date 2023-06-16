#include <bits/stdc++.h>

bool isPos(int ind, int c, vector<int> adj[], vector<int> &vis)
{
    for (auto it : adj[ind])
    {
        if (vis[it] == c)
            return false;
    }
    return true;
}

bool solve(int ind, int n, int m, vector<int> adj[], vector<int> &vis)
{
    if (ind == n)
        return true;

    for (int i = 1; i <= m; i++)
    {
        if (isPos(ind, i, adj, vis))
        {
            vis[ind] = i;
            if (solve(ind + 1, n, m, adj, vis))
                return true;
            vis[ind] = 0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m)
{
    // Write your code here
    int n = mat.size();
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (mat[i][j])
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> vis(n);
    string color = "NO";
    if (solve(0, n, m, adj, vis))
        color = "YES";

    return color;
}