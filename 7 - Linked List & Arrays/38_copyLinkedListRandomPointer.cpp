#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    LinkedListNode<int> *clone = new LinkedListNode<int>(-1);
    LinkedListNode<int> *cloneEnd = clone;
    LinkedListNode<int> *temp = head;
    while (temp)
    {
        LinkedListNode<int> *x = new LinkedListNode<int>(temp->data);
        cloneEnd->next = x;
        cloneEnd = x;
        temp = temp->next;
    }
    cloneEnd->next = NULL;
    clone = clone->next;
    temp = head;
    LinkedListNode<int> *cloneTemp = clone;
    unordered_map<LinkedListNode<int> *, LinkedListNode<int> *> mp;
    while (temp)
    {
        mp[temp] = cloneTemp;
        temp = temp->next;
        cloneTemp = cloneTemp->next;
    }
    temp = head;
    cloneTemp = clone;
    while (temp)
    {
        cloneTemp->random = mp[temp->random];
        temp = temp->next;
        cloneTemp = cloneTemp->next;
    }
    return clone;
}
