
int dx[8] = {1, -1, -1, 1, 0, 0, 1, -1};
int dy[8] = {1, -1, 1, -1, 1, -1, 0, 0};

void dfs(int i, int j, int n, int m, int **temp)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return;
    if (temp[i][j] != 1)
        return;
    temp[i][j] = 0;
    for (int k = 0; k < 8; k++)
    {
        int nx = i + dx[k];
        int ny = j + dy[k];
        dfs(nx, ny, n, m, temp);
    }
}

int getTotalIslands(int **arr, int n, int m)
{
    // Write your code here.
    int **temp = arr;
    int island = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (temp[i][j] == 1)
            {
                island++;
                dfs(i, j, n, m, temp);
            }
        }
    }
    return island;
}
