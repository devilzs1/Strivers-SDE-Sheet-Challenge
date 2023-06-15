#include <bits/stdc++.h>
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    auto comp = [&](vector<int> a, vector<int> b)
    {
        return a[1] > b[1];
    };
    sort(begin(jobs), end(jobs), comp);
    int maxProfit = 0, maxDeadline = INT_MIN;
    for (auto it : jobs)
        maxDeadline = max(maxDeadline, it[0]);
    vector<int> vis(maxDeadline + 1);

    for (auto it : jobs)
    {
        int ind = it[0];
        while (ind >= 1 && vis[ind])
            ind--;
        if (ind >= 1)
        {
            vis[ind] = 1;
            maxProfit += it[1];
        }
    }
    return maxProfit;
}
