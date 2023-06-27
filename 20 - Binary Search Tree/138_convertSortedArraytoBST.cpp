#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int> *solve(int start, int end, vector<int> &arr)
{
    if (start > end)
        return NULL;

    int mid = start + (end - start) / 2;

    TreeNode<int> *root = new TreeNode<int>(arr[mid]);
    root->left = solve(start, mid, arr);
    root->right = solve(mid + 1, end, arr);

    return root;
}

TreeNode<int> *sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    return solve(0, n - 1, arr);
}