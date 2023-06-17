#include <bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k)
{
    // Write your code here.
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pq.push(a[i] + b[j]);
        }
    }
    vector<int> sumComb;
    int times = k;
    while (times--)
    {
        int x = pq.top();
        pq.pop();
        sumComb.push_back(x);
    }
    return sumComb;
}