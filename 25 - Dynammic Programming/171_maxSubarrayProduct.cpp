#include <bits/stdc++.h>
int maximumProduct(vector<int> &arr, int n)
{
    // Write your code here
    int pref = 1, suff = 1;
    int prefRes = INT_MIN, suffRes = INT_MIN;
    bool zero = false;
    for (int i = 0; i < n; i++)
    {
        pref *= arr[i];
        if (arr[i] == 0)
        {
            zero = 1;
            pref = 1;
            continue;
        }
        prefRes = max(prefRes, pref);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        suff *= arr[i];
        if (arr[i] == 0)
        {
            zero = 1;
            suff = 1;
            continue;
        }
        suffRes = max(suffRes, suff);
    }
    if (!zero)
        return max(prefRes, suffRes);
    return max({prefRes, suffRes, 0});
}
