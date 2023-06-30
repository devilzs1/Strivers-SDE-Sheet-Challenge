#include <bits/stdc++.h>
int lcs(string s, string t)
{
    // Write your code here
    int m = s.length(), n = t.length();

    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
            }
            else
            {
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        prev = curr;
    }
    return prev[n];
}