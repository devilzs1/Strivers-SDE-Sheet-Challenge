#include <bits/stdc++.h>
double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    auto comp = [&](pair<int, int> a, pair<int, int> b)
    {
        return (a.second * 1.0 / a.first) > (b.second * 1.0 / b.first);
    };
    sort(begin(items), end(items), comp);
    double maxValue = 0;
    for (int i = 0; i < n && w > 0; i++)
    {
        if (w >= items[i].first)
        {
            maxValue += 1.0 * items[i].second;
            w -= items[i].first;
        }
        else
        {
            maxValue += (items[i].second * 1.0 / items[i].first) * w;
            w = 0;
        }
    }
    return maxValue;
}