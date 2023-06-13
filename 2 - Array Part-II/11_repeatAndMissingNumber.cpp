#include <bits/stdc++.h>

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    // Write your code here
    int missing = -1, repeat = -1;
    for (int i = 0; i < n; i++)
    {
        int x = abs(arr[i]) - 1;
        if (arr[x] > 0)
            arr[x] = -arr[x];
        else
        {
            repeat = abs(arr[i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (arr[i - 1] > 0)
        {
            missing = i;
            break;
        }
    }
    return {missing, repeat};
}
