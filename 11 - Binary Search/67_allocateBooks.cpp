#include <bits/stdc++.h>

bool isPos(long long x, int n, int m, vector<int> time)
{
    int count = 1;
    long long currTime = 0;
    for (int i = 0; i < m; i++)
    {
        if (time[i] > x)
            return false;
        currTime += 1LL * time[i];
        if (currTime > x)
        {
            count++;
            currTime = 1LL * time[i];
        }
    }
    return count <= n;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    // Write your code here.
    long long sum = 0, maxTime = 0;
    for (int i = 0; i < m; i++)
        sum += 1LL * time[i];
    long long start = 1, end = sum;
    while (start <= end)
    {
        long long mid = start + (end - start) / 2;

        if (isPos(mid, n, m, time))
        {
            maxTime = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return maxTime;
}