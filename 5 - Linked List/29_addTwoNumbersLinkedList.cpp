/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node *first = num1, *second = num2;
    Node *sum = new Node(-1);
    Node *temp = sum;
    int carry = 0;
    while (first && second)
    {
        int x = (first->data + second->data + carry) % 10;
        carry = (first->data + second->data + carry) / 10;
        Node *z = new Node(x);
        temp->next = z;
        temp = temp->next;
        first = first->next;
        second = second->next;
    }
    while (first)
    {
        int x = (first->data + carry) % 10;
        carry = (first->data + carry) / 10;
        Node *z = new Node(x);
        temp->next = z;
        temp = temp->next;
        first = first->next;
    }
    while (second)
    {
        int x = (second->data + carry) % 10;
        carry = (second->data + carry) / 10;
        Node *z = new Node(x);
        temp->next = z;
        temp = temp->next;
        second = second->next;
    }
    if (carry > 0)
    {
        Node *z = new Node(carry);
        temp->next = z;
        temp = temp->next;
    }
    sum = sum->next;
    return sum;
}
