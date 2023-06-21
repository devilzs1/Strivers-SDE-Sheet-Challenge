#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/

void trav(BinaryTreeNode<int> *temp, vector<vector<int>> &traversals)
{
    if (temp == NULL)
        return;

    traversals[1].push_back(temp->data);
    trav(temp->left, traversals);
    traversals[0].push_back(temp->data);
    trav(temp->right, traversals);
    traversals[2].push_back(temp->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here.
    vector<vector<int>> traversals(3);
    BinaryTreeNode<int> *temp = root;
    trav(temp, traversals);
    return traversals;
}