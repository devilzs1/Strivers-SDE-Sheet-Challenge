#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    vector<int> major;
    int n = arr.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto &it : mp)
    {
        if (it.second > n / 3)
            major.push_back(it.first);
    }
    return major;
}