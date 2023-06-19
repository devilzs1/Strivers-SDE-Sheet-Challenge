#include <bits/stdc++.h>
/*
    This is signature of helper function 'knows'.
    You should not implement it, or speculate about its implementation.

    bool knows(int A, int B);
    Function 'knows(A, B)' will returns "true" if the person having
    id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n)
{
    // Write your code here.
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    while (st.size() > 1)
    {
        int x = st.top();
        st.pop();
        int y = st.top();
        st.pop();
        bool f = knows(x, y), s = knows(y, x);
        if (f)
        {
            st.push(y);
        }
        else
        {
            st.push(x);
        }
    }
    int cel = st.top();
    for (int i = 0; i < n; i++)
    {
        if (i != cel)
        {
            if (knows(cel, i) || !knows(i, cel))
                return -1;
        }
    }
    return cel;
}