
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void dfs(vector<vector<int>> &flood, int x, int y, int newColor, int prev)
{

    if (x < 0 || x >= flood.size() || y < 0 || y >= flood[0].size())
        return;
    if (flood[x][y] == -1 || flood[x][y] != prev)
        return;
    flood[x][y] = -1;
    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        dfs(flood, nx, ny, newColor, prev);
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    vector<vector<int>> flood = image;
    int n = image.size(), m = image[0].size();
    int prev = image[x][y];
    dfs(flood, x, y, newColor, prev);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (flood[i][j] == -1)
                flood[i][j] = newColor;
        }
    }
    return flood;
}