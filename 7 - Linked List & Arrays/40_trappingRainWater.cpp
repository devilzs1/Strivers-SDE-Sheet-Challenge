#include <bits/stdc++.h>
long getTrappedWater(long *arr, int n)
{
    // Write your code here.
    vector<long> sufMax(n), currMax(n);
    currMax[0] = arr[0];
    sufMax[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++)
    {
        currMax[i] = max(currMax[i - 1], arr[i]);
        sufMax[n - i - 1] = max(sufMax[n - i], arr[n - i - 1]);
    }
    long water = 0;
    for (int i = 0; i < n; i++)
    {
        water += min(currMax[i], sufMax[i]) - arr[i];
    }
    return water;
}