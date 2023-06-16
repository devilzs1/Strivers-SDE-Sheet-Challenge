#include <bits/stdc++.h>
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k)
{
    // Write your code here.
    if (n < m)
    {
        swap(row1, row2);
        swap(n, m);
    }
    int start = max(0, k - n), end = min(m, k);
    while (start <= end)
    {
        int part1 = start + (end - start) / 2;
        int part2 = k - part1;
        int left1 = part1 == 0 ? INT_MIN : row1[part1 - 1];
        int left2 = part2 == 0 ? INT_MIN : row2[part2 - 1];
        int right1 = part1 == m ? INT_MAX : row1[part1];
        int right2 = part2 == n ? INT_MAX : row2[part2];

        if (left1 <= right2 && left2 <= right1)
        {
            return max(left1, left2);
        }
        else if (left1 > right2)
        {
            end = part1 - 1;
        }
        else
        {
            start = part1 + 1;
        }
    }
    return -1;
}