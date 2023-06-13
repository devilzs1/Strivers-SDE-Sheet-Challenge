#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n)
{
    // Write your code here.
    int major = arr[0], count = 1;
    for (int i = 1; i < n; i++)
    {
        if (count == 0)
            major = arr[i];

        if (arr[i] == major)
            count++;
        else
            count--;
    }
    int check = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == major)
            check++;
    }
    if (check > n / 2)
        return major;

    return -1;
}