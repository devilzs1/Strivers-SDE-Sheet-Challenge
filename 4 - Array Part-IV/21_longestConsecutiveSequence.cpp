#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    // Write your code here.
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
        st.insert(arr[i]);
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        if (st.find(x - 1) != st.end())
            continue;
        else
        {
            int count = 0;
            while (st.find(x) != st.end())
            {
                count++;
                st.erase(x);
                x++;
            }
            maxLen = max(count, maxLen);
        }
    }
    return maxLen;
}