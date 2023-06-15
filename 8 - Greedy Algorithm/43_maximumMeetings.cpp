#include <bits/stdc++.h>
vector<int> maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    set<pair<int, pair<int, int>>> st;
    int n = start.size();
    for (int i = 0; i < n; i++)
    {
        st.insert({end[i], {i + 1, start[i]}});
    }
    vector<int> meetings;
    int prevSt = -1, prevEnd = -1;
    for (auto it : st)
    {
        if (prevEnd == -1)
        {
            prevEnd = it.first;
            meetings.push_back(it.second.first);
        }

        if (it.second.second > prevEnd)
        {
            prevEnd = it.first;
            meetings.push_back(it.second.first);
        }
    }
    return meetings;
}