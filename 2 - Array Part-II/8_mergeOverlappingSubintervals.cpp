#include <bits/stdc++.h>
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    vector<vector<int>> merged;
    int n = intervals.size();
    sort(begin(intervals), end(intervals));
    int start = intervals[0][0], end = intervals[0][1];
    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] <= end)
        {
            end = max(end, intervals[i][1]);
            start = min(start, intervals[i][0]);
        }
        else
        {
            merged.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }
    merged.push_back({start, end});

    return merged;
}
