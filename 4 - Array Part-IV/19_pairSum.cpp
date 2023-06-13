#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    // Write your code here.
    vector<vector<int>> pairs;
    unordered_map<int, int> mp;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (mp.find(s - arr[i]) != mp.end())
        {
            int x = s - arr[i];
            int times = mp[x];
            while (times--)
                pairs.push_back({min(arr[i], x), max(arr[i], x)});
        }
        mp[arr[i]]++;
    }
    sort(begin(pairs), end(pairs));
    return pairs;
}