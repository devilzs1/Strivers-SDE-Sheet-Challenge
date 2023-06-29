#include <bits/stdc++.h>
vector<int> countDistinctElements(vector<int> &arr, int k)
{
    // Write your code here
    unordered_map<int, int> mp;
    int left = 0;
    for (int i = 0; i < k; i++)
        mp[arr[i]]++;
    vector<int> count;
    count.push_back(mp.size());
    for (int i = k; i < arr.size(); i++)
    {
        mp[arr[left]]--;
        if (mp[arr[left]] == 0)
            mp.erase(arr[left]);
        left++;
        mp[arr[i]]++;
        count.push_back(mp.size());
    }
    return count;
}
