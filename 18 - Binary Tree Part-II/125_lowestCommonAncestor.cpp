#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int> *solve(TreeNode<int> *root, int x, int y)
{
    if (root == NULL)
        return NULL;
    if ((root->data == x) || (root->data == y))
        return root;

    auto l = solve(root->left, x, y);
    auto r = solve(root->right, x, y);
    if (l != NULL && r != NULL)
        return root;
    else if (l == NULL && r != NULL)
        return r;
    else if (l != NULL && r == NULL)
        return l;
    else
        return NULL;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    //    Write your code here
    auto node = solve(root, x, y);
    return node->data;
}