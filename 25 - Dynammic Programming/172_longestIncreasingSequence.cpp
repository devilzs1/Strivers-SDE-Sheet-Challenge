#include <bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> curr;
    curr.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > curr.back())
            curr.push_back(arr[i]);
        else
        {
            int ind = (lower_bound(begin(curr), end(curr), arr[i]) - begin(curr));
            if (ind != n)
                curr[ind] = arr[i];
        }
    }
    return curr.size();
}
