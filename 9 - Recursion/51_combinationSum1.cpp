void solve(int ind, int target, int k, vector<int> &arr, vector<vector<int>> &subsetSum, vector<int> &temp)
{
    if (ind == arr.size())
    {
        if (target == k)
        {
            subsetSum.push_back(temp);
        }
        return;
    }
    solve(ind + 1, target, k, arr, subsetSum, temp);
    temp.push_back(arr[ind]);
    solve(ind + 1, target + arr[ind], k, arr, subsetSum, temp);
    temp.pop_back();
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> subsetSum;
    vector<int> temp;
    solve(0, 0, k, arr, subsetSum, temp);
    return subsetSum;
}
