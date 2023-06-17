#include <bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    vector<int> frequent;
    vector<pair<int, int>> temp;
    for (auto it : mp)
    {
        temp.push_back({it.second, it.first});
    }
    sort(begin(temp), end(temp), greater<pair<int, int>>());
    for (int i = 0; i < k; i++)
    {
        frequent.push_back(temp[i].second);
    }
    sort(begin(frequent), end(frequent));
    return frequent;
}