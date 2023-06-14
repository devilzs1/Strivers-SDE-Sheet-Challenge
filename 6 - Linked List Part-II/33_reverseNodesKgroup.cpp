#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/

Node *reverse(Node *head, int n, int b[], int ind)
{
    if (n == 0 || !head || !head->next)
        return head;

    Node *prev = NULL, *curr = head, *currNext = NULL;
    while (b[ind] == 0 && ind < n)
        ++ind;
    if (ind < n)
    {
        int len = b[ind];
        while (len-- && curr)
        {
            currNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currNext;
        }
    }
    if (ind >= n && curr)
        return head;

    if (curr)
    {
        head->next = reverse(currNext, n, b, ind + 1);
    }
    return prev;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[])
{
    // Write your code here.
    int ind = 0;
    head = reverse(head, n, b, ind);
    return head;
}