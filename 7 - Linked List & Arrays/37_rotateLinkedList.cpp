/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

int length(Node *head)
{
    Node *slow = head;
    int len = 0;
    while (slow)
    {
        slow = slow->next;
        len++;
    }
    return len;
}

Node *rotate(Node *head, int k)
{
    // Write your code here.
    int len = length(head);
    k %= len;
    if (k == 0)
        return head;
    int x = len - k - 1;
    Node *slow = head;
    while (x--)
        slow = slow->next;
    Node *temp = slow->next;
    slow->next = NULL;
    Node *start = temp;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = head;
    head = start;
    return head;
}