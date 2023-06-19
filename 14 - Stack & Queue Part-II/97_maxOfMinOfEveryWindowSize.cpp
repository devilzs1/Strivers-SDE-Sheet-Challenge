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

vector<int> maxMinWindow(vector<int> a, int n)
{
    // Write your code here.
    vector<int> nse, pse;
    nse = nextSmaller(a);
    pse = prevSmaller(a);
    vector<int> maxWin(n, INT_MIN);
    for (int i = 0; i < n; i++)
    {
        if (nse[i] == -1)
            nse[i] = n;

        int size = nse[i] - pse[i] - 1;
        maxWin[size - 1] = max(maxWin[size - 1], a[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        maxWin[i] = max(maxWin[i + 1], maxWin[i]);
    }
    return maxWin;
}