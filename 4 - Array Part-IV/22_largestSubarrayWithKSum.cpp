#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector<int> &arr)
{

    // Write your code here
    int n = arr.size(), maxLen = 0;
    int sum = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (arr[i] == 0)
            maxLen = max(maxLen, 1);
        if (sum == 0)
            maxLen = max(maxLen, i + 1);

        if (mp.find(sum) != mp.end())
        {
            maxLen = max(maxLen, i - mp[sum]);
        }
        else
            mp[sum] = i;
    }
    return maxLen;
}