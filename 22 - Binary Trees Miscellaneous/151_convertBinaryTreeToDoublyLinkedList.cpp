#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

BinaryTreeNode<int> *BTtoDLL(BinaryTreeNode<int> *root)
{
    // Write your code here
    BinaryTreeNode<int> *temp = root;
    BinaryTreeNode<int> *prev = NULL, *head = NULL;
    while (temp)
    {
        if (temp->left)
        {
            BinaryTreeNode<int> *next = temp->left;
            while (next->right && next->right != temp)
            {
                next = next->right;
            }
            if (next->right == NULL)
            {
                next->right = temp;
                temp = temp->left;
            }
            else if (next->right == temp)
            {
                temp->left = next;
                prev = temp;
                temp = temp->right;
            }
        }
        else
        {
            if (head == NULL)
                head = temp;
            temp->left = prev;
            if (prev != NULL)
                prev->right = temp;
            prev = temp;
            temp = temp->right;
        }
    }
    return head;
}