#include <bits/stdc++.h>

bool isValid(int i, int j, int n, int m)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
int minTimeToRot(vector<vector<int>> &grid, int n, int m)
{
    // Write your code here.
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int minTime = 0, fresh = 0;
    vector<vector<int>> mat = grid;
    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 2)
                q.push({0, {i, j}});
            else if (mat[i][j] == 1)
                fresh++;
        }
    }
    if (fresh == 0)
        return 0;
    int countFresh = 0;
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        int time = node.first, i = node.second.first, j = node.second.second;
        minTime = max(minTime, time);
        for (int k = 0; k < 4; k++)
        {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (isValid(nx, ny, n, m) && mat[nx][ny] == 1)
            {
                q.push({time + 1, {nx, ny}});
                mat[nx][ny] = 0;
                countFresh++;
            }
        }
    }
    if (countFresh == fresh)
        return minTime;
    return -1;
}