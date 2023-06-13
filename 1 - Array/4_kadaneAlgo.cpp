#include <bits/stdc++.h>
long long maxSubarraySum(int arr[], int n)
{
    long long sum = 0, curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr = max(1ll * arr[i], 1ll * arr[i] + curr);
        sum = max(sum, curr);
    }
    return sum;
}