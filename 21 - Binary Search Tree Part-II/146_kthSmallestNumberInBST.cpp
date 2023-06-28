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
TreeNode<int> *solve(TreeNode<int> *root, int &k)
{
    if (root == NULL)
        return NULL;

    TreeNode<int> *curr = solve(root->left, k);
    if (curr)
        return curr;

    if (--k == 0)
        return root;

    return solve(root->right, k);
}
int kthSmallest(TreeNode<int> *root, int k)
{
    //	Write the code here.
    int num = -1, x = k;
    TreeNode<int> *temp = solve(root, x);
    if (temp)
        num = temp->data;

    return num;
}