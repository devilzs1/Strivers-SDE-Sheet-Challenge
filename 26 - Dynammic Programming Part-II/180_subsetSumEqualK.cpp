#include <bits/stdc++.h>
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<bool> prev(k + 1, false);
    prev[0] = true;
    for (int i = 1; i <= n; i++)
    {
        vector<bool> curr(k + 1, false);
        for (int j = 0; j <= k; j++)
        {
            curr[j] = prev[j];
            if (j - arr[i - 1] >= 0)
            {
                curr[j] = (prev[j] || prev[j - arr[i - 1]]);
            }
        }
        prev = curr;
    }
    return prev[k];
}