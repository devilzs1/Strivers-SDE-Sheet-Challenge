#include <bits/stdc++.h>

class Queue
{
    // Define the data members(if any) here.
    stack<int> st1, st2;

public:
    Queue()
    {
        // Initialize your data structure here.
    }

    void enQueue(int val)
    {
        // Implement the enqueue() function.
        st1.push(val);
    }

    int deQueue()
    {
        // Implement the dequeue() function.
        int deq = -1;
        if (st1.size() == 0 && st2.size() == 0)
            return deq;
        if (st2.size() == 0)
        {
            while (st1.size())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        deq = st2.top();
        st2.pop();
        return deq;
    }

    int peek()
    {
        // Implement the peek() function here.
        int deq = -1;
        if (st1.size() == 0 && st2.size() == 0)
            return deq;
        if (st2.size() == 0)
        {
            while (st1.size())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        deq = st2.top();
        return deq;
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function here.
        return (st1.size() == 0 && st2.size() == 0);
    }
};