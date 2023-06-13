#include <bits/stdc++.h>

long long mergeCount(int start, int mid, int end, long long *arr, int n)
{
    int i = start, j = mid + 1, k = start;
    long long count = 0;
    vector<long long> temp(n);
    while (i <= mid && j <= end)
    {
        if (arr[i] > arr[j])
        {
            temp[k++] = arr[j++];
            count += (long long)(mid - i + 1);
        }
        else
        {
            temp[k++] = arr[i++];
        }
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= end)
        temp[k++] = arr[j++];
    for (int k = start; k <= end; k++)
    {
        arr[k] = temp[k];
    }

    return count;
}

long long calc(int start, int end, long long *arr, int n)
{
    if (start >= end)
        return 0;

    long long count = 0;
    int mid = start + (end - start) / 2;
    count += calc(start, mid, arr, n);
    count += calc(mid + 1, end, arr, n);
    count += mergeCount(start, mid, end, arr, n);

    return count;
}
long long getInversions(long long *arr, int n)
{
    // Write your code here.
    return calc(0, n - 1, arr, n);
}