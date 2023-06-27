#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    // Write your code here.
    pair<int, int> predsucc = {-1, -1};
    BinaryTreeNode<int> *temp = root;
    while (temp)
    {
        if (temp->data == key)
            break;

        if (temp->data < key)
        {
            predsucc.first = temp->data;
            temp = temp->right;
        }
        else
        {
            predsucc.second = temp->data;
            temp = temp->left;
        }
    }
    BinaryTreeNode<int> *curr = temp->left;
    while (curr)
    {
        predsucc.first = curr->data;
        curr = curr->right;
    }
    curr = temp->right;
    while (curr)
    {
        predsucc.second = curr->data;
        curr = curr->left;
    }
    return predsucc;
}
