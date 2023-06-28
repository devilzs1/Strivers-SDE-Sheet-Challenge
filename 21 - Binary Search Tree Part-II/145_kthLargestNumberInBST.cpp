#include <bits/stdc++.h>
/************************************************************
    Following is the Binary Search Tree node structure

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
TreeNode<int> *solve(TreeNode<int> *root, int &k)
{
    if (root == NULL)
        return NULL;

    TreeNode<int> *curr = solve(root->right, k);
    if (curr)
        return curr;

    if (--k == 0)
        return root;

    return solve(root->left, k);
}

int KthLargestNumber(TreeNode<int> *root, int k)
{
    // Write your code here.
    int num = -1, x = k;
    TreeNode<int> *temp = solve(root, x);
    if (temp)
        num = temp->data;
    return num;
}
