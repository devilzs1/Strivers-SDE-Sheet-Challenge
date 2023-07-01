#include <bits/stdc++.h>
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int n = jobs.size(), mxdead = 0;
    for (int i = 0; i < n; i++)
    {
        mxdead = max(mxdead, jobs[i][0]);
    }
    vector<int> time(mxdead + 1, 0);
    auto comp = [&](vector<int> &a, vector<int> &b)
    {
        return a[1] > b[1];
    };
    sort(begin(jobs), end(jobs), comp);
    int profit = 0;
    for (auto it : jobs)
    {
        int pos = it[0];
        while (pos >= 1 && time[pos] == 1)
            pos--;
        if (pos >= 1)
        {
            profit += it[1];
            time[pos] = 1;
        }
    }
    return profit;
}
