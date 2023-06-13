#include <bits/stdc++.h>
void sort012(int *arr, int n)
{
    //   Write your code here
    int start = 0, end = n - 1, mid = 0;
    while (mid <= end)
    {
        if (arr[mid] == 1)
            mid++;
        else if (arr[mid] == 0)
        {
            swap(arr[start++], arr[mid++]);
        }
        else
        {
            swap(arr[end--], arr[mid]);
        }
    }
}