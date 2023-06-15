#include <bits/stdc++.h>

void solve(int ind, vector<int> &arr, set<vector<int>> &subset, vector<int> &temp)
{
    if (ind == arr.size())
    {
        subset.insert(temp);
        return;
    }
    solve(ind + 1, arr, subset, temp);
    temp.push_back(arr[ind]);
    solve(ind + 1, arr, subset, temp);
    temp.pop_back();
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    set<vector<int>> subset;
    vector<int> temp;
    sort(begin(arr), end(arr));
    solve(0, arr, subset, temp);
    vector<vector<int>> unSubset;
    for (auto it : subset)
        unSubset.push_back(it);
    return unSubset;
}