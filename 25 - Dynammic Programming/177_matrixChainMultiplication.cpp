#include <bits/stdc++.h>

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int mini = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int cost = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                mini = min(cost, mini);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N - 1];
}