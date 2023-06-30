#include <bits/stdc++.h>

int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if (i == s.length())
    {
        if (j == t.length())
            return 0;

        return t.length() - j;
    }
    if (j == t.length())
    {
        if (i == s.length())
            return 0;
        return s.length() - i;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == t[j])
        return solve(i + 1, j + 1, s, t, dp);

    int insert = 1 + solve(i, j + 1, s, t, dp);
    int del = 1 + solve(i + 1, j, s, t, dp);
    int rep = 1 + solve(i + 1, j + 1, s, t, dp);

    return dp[i][j] = min({insert, del, rep});
}

int editDistance(string str1, string str2)
{
    // write you code here
    int n = str1.length(), m = str2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(0, 0, str1, str2, dp);
}