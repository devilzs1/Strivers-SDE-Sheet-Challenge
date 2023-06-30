int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    // Write your code here.
    long maxi = 1000000000;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, maxi));
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
        dist[u][v] = wt;
        // dist[v][u] = wt;
    }
    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] < maxi && dist[k][j] < maxi)
                {
                    dist[i][j] = min(dist[i][j], (dist[i][k] + dist[k][j]));
                }
            }
        }
    }
    return dist[src][dest];
}