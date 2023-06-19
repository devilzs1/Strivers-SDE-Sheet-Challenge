#include <bits/stdc++.h>

bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> st;
    int n = expression.length();
    for (int i = 0; i < n; i++)
    {
        char x = expression[i];
        if (x == '(' || x == '{' || x == '[')
            st.push(x);
        else
        {
            if (st.empty())
                return false;
            char y = st.top();
            if ((y == '(' && x == ')') || (y == '{' && x == '}') || (y == '[' && x == ']'))
                st.pop();
            else
                return false;
        }
    }
    return (st.size() == 0);
}