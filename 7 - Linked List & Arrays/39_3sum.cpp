#include <bits/stdc++.h>
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    // Write your code here.
    sort(begin(arr), end(arr));
    unordered_set<vector<int>> temp;
    for (int i = 0; i < n; i++)
    {
        int left = i + 1, right = n - 1;
        while (left < right)
        {
            int sum = arr[i] + arr[left] + arr[right];
            if (sum == K)
            {
                temp.insert({arr[i], arr[left], arr[right]});
                left++, right--;
            }
            else if (sum < K)
                left++;
            else
                right--;
        }
    }
    vector<vector<int>> triples;
    for (auto it : temp)
    {
        triples.push_back(it);
    }
    return triples;
}