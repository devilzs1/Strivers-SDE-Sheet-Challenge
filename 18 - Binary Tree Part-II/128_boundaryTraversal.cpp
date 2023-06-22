#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void travLeft(TreeNode<int> *root, vector<int> &bound)
{
    if (root == NULL)
        return;
    TreeNode<int> *temp = root->left;
    while (temp)
    {
        if (temp->left != NULL || temp->right != NULL)
            bound.push_back(temp->data);
        if (temp->left)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return;
}
void travRight(TreeNode<int> *root, vector<int> &bound)
{
    if (root == NULL)
        return;
    TreeNode<int> *temp = root->right;
    vector<int> z;
    while (temp)
    {
        if (temp->left != NULL || temp->right != NULL)
            z.push_back(temp->data);
        if (temp->right)
            temp = temp->right;
        else
            temp = temp->left;
    }
    for (int i = z.size() - 1; i >= 0; i--)
        bound.push_back(z[i]);
    return;
}
void travLeaf(TreeNode<int> *root, vector<int> &bound)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        bound.push_back(root->data);
    travLeaf(root->left, bound);
    travLeaf(root->right, bound);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    // Write your code here.

    if (root->left == NULL && root->right == NULL)
        return {root->data};
    vector<int> bound;
    bound.push_back(root->data);
    travLeft(root, bound);
    travLeaf(root, bound);
    travRight(root, bound);
    return bound;
}