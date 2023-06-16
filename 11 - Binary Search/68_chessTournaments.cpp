#include <bits/stdc++.h>

bool isPos(int focus, int n, int c, vector<int> &positions)
{
    int count = 1, currPos = positions[0];
    for (int i = 1; i < n; i++)
    {
        if (positions[i] >= currPos + focus)
        {
            count++;
            currPos = positions[i];
        }
    }
    return count >= c;
}

int chessTournament(vector<int> positions, int n, int c)
{
    // Write your code here
    sort(positions.begin(), positions.end());
    int start = 0, end = positions[n - 1], focus = 0;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPos(mid, n, c, positions))
        {
            focus = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return focus;
}