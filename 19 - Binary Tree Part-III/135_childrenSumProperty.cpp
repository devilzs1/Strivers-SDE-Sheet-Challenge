#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

void changeTree(BinaryTreeNode<int> *root)
{
    // Write your code here.
    if (root == NULL)
        return;
    int csum = 0;
    if (root->right)
        csum += root->right->data;
    if (root->left)
        csum += root->left->data;

    if (root->data > csum)
    {
        if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }
    else
    {
        root->data = csum;
    }
    changeTree(root->left);
    changeTree(root->right);

    int fsum = 0;
    if (root->left)
        fsum += root->left->data;
    if (root->right)
        fsum += root->right->data;
    if (root->left || root->right)
        root->data = fsum;
    return;
}