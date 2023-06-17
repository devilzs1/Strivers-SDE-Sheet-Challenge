#include <bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    // Write your code here.
    if (k == 1)
        return kArrays[0];
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < kArrays[i].size(); j++)
        {
            pq.push(kArrays[i][j]);
        }
    }
    vector<int> merged;
    while (!pq.empty())
    {
        int x = pq.top();
        pq.pop();
        merged.push_back(x);
    }
    return merged;
}
