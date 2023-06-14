/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *removeKthNode(Node *head, int K)
{
    // Write your code here.
    Node *slow = head, *fast = head;
    int len = K;
    while (len--)
        fast = fast->next;

    if (!fast)
        return head->next;
    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    Node *temp = slow->next->next;
    free(slow->next);
    slow->next = temp;
    return head;
}
