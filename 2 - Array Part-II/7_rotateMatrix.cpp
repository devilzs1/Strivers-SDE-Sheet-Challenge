#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    if (n == 1 || m == 1)
        return;

    int srow = 0, scol = 0, erow = n - 1, ecol = m - 1;
    while (srow < erow && scol < ecol)
    {
        int x = mat[srow][scol];
        for (int j = scol + 1; j <= ecol; j++)
        {
            int y = mat[srow][j];
            mat[srow][j] = x;
            x = y;
        }
        for (int i = srow + 1; i <= erow; i++)
        {
            int y = mat[i][ecol];
            mat[i][ecol] = x;
            x = y;
        }
        ecol--;
        for (int j = ecol; j >= scol; j--)
        {
            int y = mat[erow][j];
            mat[erow][j] = x;
            x = y;
        }
        erow--;
        for (int i = erow; i >= srow; i--)
        {
            int y = mat[i][scol];
            mat[i][scol] = x;
            x = y;
        }
        scol++;
        srow++;
    }
}