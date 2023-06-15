#include <bits/stdc++.h>

void solve(int ind, int k, int target, vector<int> &arr,
           vector<vector<int>> &subset, vector<int> &temp)
{
    if (k == target)
    {
        subset.push_back(temp);
        return;
    }
    if (ind == arr.size())
    {
        return;
    }
    for (int i = ind; i < arr.size(); i++)
    {
        if (i > ind && arr[i] == arr[i - 1])
            continue;

        temp.push_back(arr[i]);
        solve(i + 1, k + arr[i], target, arr, subset, temp);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    // Write your code here.
    vector<vector<int>> subset;
    vector<int> temp;
    sort(begin(arr), end(arr));
    solve(0, 0, target, arr, subset, temp);
    return subset;
}
