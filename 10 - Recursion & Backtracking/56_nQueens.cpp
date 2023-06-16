
void solve(int ind, int n, vector<int> &col, vector<int> &upDiag, vector<int> &lowDiag,
           vector<vector<int>> &queens, vector<vector<int>> temp)
{
    if (ind == n)
    {
        vector<int> curr;
        for (auto it : temp)
        {
            for (auto it1 : it)
                curr.push_back(it1);
        }
        queens.push_back(curr);
        curr.clear();
        return;
    }

    for (int x = 0; x < n; x++)
    {
        if (!col[x] && !lowDiag[x + ind] && !upDiag[n - 1 + ind - x])
        {
            col[x] = 1;
            lowDiag[x + ind] = 1;
            upDiag[n - 1 + ind - x] = 1;
            temp[x][ind] = 1;
            solve(ind + 1, n, col, upDiag, lowDiag, queens, temp);
            col[x] = 0;
            lowDiag[x + ind] = 0;
            upDiag[n - 1 + ind - x] = 0;
            temp[x][ind] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n)
{
    // Write your code here.
    vector<int> col(n), upDiag(2 * n), lowDiag(2 * n);
    vector<vector<int>> queens;
    vector<vector<int>> temp(n, vector<int>(n, 0));
    solve(0, n, col, upDiag, lowDiag, queens, temp);

    return queens;
}