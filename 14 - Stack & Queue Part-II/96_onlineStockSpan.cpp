#include <bits/stdc++.h>
vector<int> findSpans(vector<int> &price)
{
    // Write your code here.
    int n = price.size();
    vector<int> span(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && price[i] > price[st.top()])
        {
            span[st.top()] = st.top() - i;
            st.pop();
        }
        st.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        if (span[i] == -1)
        {
            span[i] = i + 1;
        }
    }
    return span;
}