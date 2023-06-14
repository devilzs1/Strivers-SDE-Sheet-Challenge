#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    // Write your code here.
    Node<int> *temp = new Node<int>(-1);
    Node<int> *head = temp;
    while (first && second)
    {
        if (first->data < second->data)
        {
            temp->next = first;
            first = first->next;
        }
        else
        {
            temp->next = second;
            second = second->next;
        }
        temp = temp->next;
    }
    while (first)
    {
        temp->next = first;
        first = first->next;
        temp = temp->next;
    }
    while (second)
    {
        temp->next = second;
        second = second->next;
        temp = temp->next;
    }
    head = head->next;
    return head;
}
