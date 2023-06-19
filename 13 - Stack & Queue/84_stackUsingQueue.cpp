#include <bits/stdc++.h>
class Stack
{
    // Define the data members.
    queue<int> q1, q2;

public:
    Stack()
    {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        // Implement the getSize() function.
        int size = max((int)q1.size(), (int)q2.size());
        return size;
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function.
        return (q1.size() == 0 && q2.size() == 0);
    }

    void push(int element)
    {
        // Implement the push() function.
        if (q1.size())
            q1.push(element);
        else
            q2.push(element);
    }

    int pop()
    {
        // Implement the pop() function.
        int top = -1;
        if (q1.size() == 0 && q2.size() == 0)
            return top;
        if (q1.size() == 0)
        {
            while (q2.size() > 1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            top = q2.front();
            q2.pop();
        }
        else
        {
            while (q1.size() > 1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            top = q1.front();
            q1.pop();
        }

        return top;
    }

    int top()
    {
        // Implement the top() function.
        int top = -1;
        if (q1.size() == 0 && q2.size() == 0)
            return top;
        if (q1.size() == 0)
        {
            while (q2.size() > 1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            top = q2.front();
            q1.push(top);
            q2.pop();
        }
        else
        {
            while (q1.size() > 1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            top = q1.front();
            q2.push(top);
            q1.pop();
        }

        return top;
    }
};