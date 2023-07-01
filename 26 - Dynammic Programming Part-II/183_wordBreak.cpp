#include <bits/stdc++.h>
bool wordBreak(vector<string> &arr, int n, string &target)
{
    // Write your code here.
    int sz = target.length();
    vector<bool> dp(sz + 1);
    dp[sz] = 1;
    for (int i = sz - 1; i >= 0; i--)
    {
        for (auto it : arr)
        {
            int len = it.length();
            if (i + len <= sz && target.substr(i, len) == it)
            {
                dp[i] = dp[i + len];
                if (dp[i])
                    break;
            }
        }
    }
    return dp[0];
}