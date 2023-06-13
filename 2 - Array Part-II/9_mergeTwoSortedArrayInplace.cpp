#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    // Write your code here.
    int ind = m + n - 1, first = m - 1, second = n - 1;
    while (first >= 0 && second >= 0)
    {
        if (arr1[first] < arr2[second])
            arr1[ind--] = arr2[second--];
        else
            arr1[ind--] = arr1[first--];
    }
    while (second >= 0)
        arr1[ind--] = arr2[second--];
    while (first >= 0)
        arr1[ind--] = arr1[first--];

    return arr1;
}