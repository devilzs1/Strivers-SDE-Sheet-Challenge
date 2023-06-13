#include <bits/stdc++.h>

int binSearch(int start, int end, int target, vector<int> &arr)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (target > 2 * arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return (start - 1);
}

int mergeCount(int start, int mid, int end, vector<int> &arr)
{
    int i = start, j = mid + 1;
    int n = arr.size(), count = 0;
    vector<int> temp;
    while (i <= mid)
    {
        j = binSearch(mid + 1, end, arr[i], arr);
        i++;
        count += j - mid;
    }
    i = start, j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (arr[i] > arr[j])
        {
            temp.push_back(arr[j++]);
        }
        else
        {
            temp.push_back(arr[i++]);
        }
    }
    while (i <= mid)
        temp.push_back(arr[i++]);
    while (j <= end)
        temp.push_back(arr[j++]);

    for (int ind = start; ind <= end; ind++)
    {
        arr[ind] = temp[ind - start];
    }
    return count;
}

int calc(int start, int end, vector<int> &arr)
{
    if (start >= end)
        return 0;

    int count = 0;
    int mid = start + (end - start) / 2;
    count += calc(start, mid, arr);
    count += calc(mid + 1, end, arr);
    count += mergeCount(start, mid, end, arr);

    return count;
}
int reversePairs(vector<int> &arr, int n)
{
    // Write your code here.
    return calc(0, n - 1, arr);
}