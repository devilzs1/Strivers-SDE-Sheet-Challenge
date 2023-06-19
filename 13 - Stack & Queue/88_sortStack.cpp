#include <bits/stdc++.h>
void insert(stack<int> &st, int val)
{
    if (st.empty() || (!st.empty() && st.top() < val))
    {
        st.push(val);
        return;
    }
    int temp = st.top();
    st.pop();
    insert(st, val);
    st.push(temp);
}
void sortStack(stack<int> &stack)
{
    // Write your code here
    if (stack.empty())
        return;

    int temp = stack.top();
    stack.pop();
    sortStack(stack);
    insert(stack, temp);
}