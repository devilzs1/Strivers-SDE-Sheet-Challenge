
#include <bits/stdc++.h>
long countWays(int ind, int n, int value,
               int *denominations, vector<vector<long>> &dp)
{
    if (ind == n)
    {
        if (value == 0)
            return 1;
        return 0;
    }
    if (dp[ind][value] != -1)
        return dp[ind][value];
    long notpick = 0 + countWays(ind + 1, n, value, denominations, dp);
    long pick = 0;
    if (value - denominations[ind] >= 0)
        pick += countWays(ind, n, value - denominations[ind], denominations, dp);
    return dp[ind][value] = pick + notpick;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Write your code here
    vector<vector<long>> dp(n + 1, vector<long>(value + 1, -1));
    return countWays(0, n, value, denominations, dp);
}