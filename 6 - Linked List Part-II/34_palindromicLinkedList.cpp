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
int length(LinkedListNode<int> *head)
{
    LinkedListNode<int> *slow = head;
    int len = 0;
    while (slow)
    {
        len++;
        slow = slow->next;
    }
    return len;
}
LinkedListNode<int> *reverse(LinkedListNode<int> *head, int len)
{
    LinkedListNode<int> *prev = NULL, *curr = head, *currNext = head;
    while (len-- && curr)
    {
        currNext = curr->next;
        curr->next = prev;
        prev = curr;
        curr = currNext;
    }
    return prev;
}
bool isPalindrome(LinkedListNode<int> *head)
{
    // Write your code here.
    LinkedListNode<int> *slow = head;
    int len = length(head);
    if (len == 1)
        return true;

    int x = (len + 1) / 2, k = x;
    while (k--)
    {
        slow = slow->next;
    }
    LinkedListNode<int> *temp = reverse(head, x);
    if (len & 1)
        temp = temp->next;

    while (slow)
    {
        if (slow->data != temp->data)
            return false;
        slow = slow->next;
        temp = temp->next;
    }
    return true;
}