#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    unordered_map<int, int> mp;
    int n = arr.size(), subCount = 0, currXor = 0;
    for (int i = 0; i < n; i++)
    {
        currXor = (currXor ^ arr[i]);
        if (currXor == x)
            subCount++;
        if (mp.find(currXor ^ x) != mp.end())
        {
            subCount += mp[currXor ^ x];
        }
        mp[currXor]++;
    }
    return subCount;
}