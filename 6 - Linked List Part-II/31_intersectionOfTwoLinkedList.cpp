/****************************************************************

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

*****************************************************************/

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

Node *findIntersection(Node *firstHead, Node *secondHead)
{
    // Write your code here
    if (!firstHead || !secondHead)
        return NULL;

    int flen = length(firstHead), slen = length(secondHead);
    Node *first = firstHead, *second = secondHead;

    if (flen > slen)
    {
        while (flen > slen)
        {
            first = first->next;
            flen--;
        }
    }

    if (slen > flen)
    {
        while (slen > flen)
        {
            second = second->next;
            slen--;
        }
    }

    while (first && second)
    {
        if (first == second)
            return first;

        first = first->next;
        second = second->next;
    }

    return NULL;
}