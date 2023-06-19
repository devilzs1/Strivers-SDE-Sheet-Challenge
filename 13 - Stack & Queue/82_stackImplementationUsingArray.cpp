#include <bits/stdc++.h>
// Stack class.
class Stack
{

public:
    vector<int> stack;
    int ind = 0;
    Stack(int capacity)
    {
        // Write your code here.
        stack.resize(capacity);
    }

    void push(int num)
    {
        // Write your code here.
        if (ind < stack.size())
            stack[ind++] = num;
    }

    int pop()
    {
        // Write your code here.
        int top = -1;
        if (ind > 0)
            top = stack[--ind];

        return top;
    }

    int top()
    {
        // Write your code here.
        if (ind > 0)
            return stack[ind - 1];
        return -1;
    }

    int isEmpty()
    {
        // Write your code here.
        if (ind == 0)
            return 1;
        return 0;
    }

    int isFull()
    {
        // Write your code here.
        return (ind == stack.size());
    }
};