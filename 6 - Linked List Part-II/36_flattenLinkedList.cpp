/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node *merge(Node *first, Node *second)
{
    Node *temp = new Node();
    Node *merged = temp;
    while (first && second)
    {
        if (first->data < second->data)
        {
            temp->child = first;
            temp->next = NULL;
            temp = temp->child;
            first = first->child;
        }
        else
        {
            temp->child = second;
            temp->next = NULL;
            temp = second;
            second = second->child;
        }
    }
    while (first)
    {
        temp->child = first;
        temp->next = NULL;
        temp = temp->child;
        first = first->child;
    }
    while (second)
    {
        temp->child = second;
        temp->next = NULL;
        temp = temp->child;
        second = second->child;
    }
    merged = merged->child;
    return merged;
}

Node *flattenLinkedList(Node *head)
{
    // Write your code here
    if (head == NULL)
        return head;

    Node *curr = head, *currNext = head->next;
    curr->next = NULL;
    Node *temp = flattenLinkedList(currNext);

    Node *flat = merge(curr, temp);
    return flat;
}
