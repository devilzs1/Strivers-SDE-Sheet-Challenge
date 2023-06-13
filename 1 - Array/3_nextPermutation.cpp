#include <bits/stdc++.h>

// I have to figure out why it is giving TLE on some test-cases on Code Studio.
// N = 10000 & T(testcases) = 50 & below code Time complexity: ~ O(n)
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int peak = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (permutation[i] < permutation[i + 1])
        {
            peak = i;
            break;
        }
    }
    if (peak == -1)
    {
        reverse(begin(permutation), end(permutation));
    }
    else
    {
        for (int i = n - 1; i > peak; i++)
        {
            if (permutation[i] > permutation[peak])
            {
                swap(permutation[peak], permutation[i]);
                break;
            }
        }
        reverse(begin(permutation) + peak + 1, end(permutation));
    }
    return permutation;

    //using STL library function
    // next_permutation(begin(permutation), end(permutation));
    // return permutation;
}




