#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

void deleteNode(LinkedListNode<int> *node)
{
    // Write your code here.
    LinkedListNode<int> *fast = node;
    while (fast->next->next)
    {
        fast->data = fast->next->data;
        fast = fast->next;
    }
    fast->data = fast->next->data;
    free(fast->next);
    fast->next = NULL;
    return;
}