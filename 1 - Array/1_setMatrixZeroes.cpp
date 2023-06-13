#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
    // Write your code here.
    bool firstRow = false, firstCol = false;
    int n = matrix.size(), m = matrix[0].size();
    for (int j = 0; j < m; j++)
    {
        if (matrix[0][j] == 0)
            firstRow = true;
    }
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] == 0)
            firstCol = true;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }
    if (firstRow)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[0][j] = 0;
        }
    }
    if (firstCol)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }
}