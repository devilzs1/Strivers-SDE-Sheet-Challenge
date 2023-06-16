#include <bits/stdc++.h>
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void solve(int i, int j, int n, vector<vector<int>> &maze, vector<vector<int>> &paths)
{
    if (i == n - 1 && j == n - 1)
    {
        if (maze[i][j] == 1)
        {
            maze[i][j] = -1;
            vector<int> curr;
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < n; l++)
                {
                    if (maze[k][l] == -1)
                    {
                        curr.push_back(1);
                    }
                    else
                    {
                        curr.push_back(0);
                    }
                }
            }
            maze[i][j] = 1;
            paths.push_back(curr);
            curr.clear();
        }
        return;
    }

    if (i < 0 || i == n || j < 0 || j == n)
        return;
    if (maze[i][j] == 0 || maze[i][j] == -1)
        return;

    for (int k = 0; k < 4; k++)
    {
        maze[i][j] = -1;
        int nx = i + dx[k], ny = j + dy[k];
        solve(nx, ny, n, maze, paths);
        maze[i][j] = 1;
    }
}
vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n)
{
    // Write your code here.
    vector<vector<int>> paths;

    solve(0, 0, n, maze, paths);
    return paths;
}