#include <bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish)
{
    // Write your code here.
    set<pair<int, int>> st;
    int n = start.size();
    for (int i = 0; i < n; i++)
        st.insert({finish[i], start[i]});

    int maxAct = 0, currAct = 0, prev = -1;
    for (auto &it : st)
    {
        if (prev == -1)
        {
            prev = it.first;
            maxAct++;
            continue;
        }

        if (it.second >= prev)
        {
            maxAct++;
            prev = it.first;
        }
    }
    return maxAct;
}