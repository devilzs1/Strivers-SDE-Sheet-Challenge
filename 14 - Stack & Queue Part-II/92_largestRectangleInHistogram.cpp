#include <bits/stdc++.h>

vector<int> nextSmaller(vector<int> &arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> nse(n, -1);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
        {
            nse[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return nse;
}
vector<int> prevSmaller(vector<int> &arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> pse(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
        {
            pse[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return pse;
}

int largestRectangle(vector<int> &heights)
{
    // Write your code here.
    int n = heights.size();
    vector<int> nse, pse;
    nse = nextSmaller(heights);
    pse = prevSmaller(heights);

    long long maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int currHeight = heights[i];
        if (nse[i] == -1)
            nse[i] = n;
        int breadth = nse[i] - pse[i] - 1;
        long long area = (long long)(currHeight * 1LL * breadth);
        maxArea = max(maxArea, area);
    }
    return maxArea;
}