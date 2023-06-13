#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> freq(n);
    for (auto it : arr)
        freq[it]++;
    int dup = -1;
    for (int i = 1; i < n; i++)
    {
        if (freq[i] > 1)
        {
            dup = i;
            break;
        }
    }
    return dup;
}
