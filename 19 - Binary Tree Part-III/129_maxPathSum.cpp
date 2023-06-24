#include <bits/stdc++.h>
/************************************************************

    Following is the Tree node structure

    template <typename T>
    class TreeNode
    {
        public :
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

long long sumPath(TreeNode<int> *root, long long &maxSum)
{
    if (root == NULL)
        return 0;

    long long left = sumPath(root->left, maxSum);
    long long right = sumPath(root->right, maxSum);

    maxSum = max(maxSum, root->val + left + right);
    long long ans = root->val + max(left, right);
    return ans;
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    if (root == NULL || root->left == NULL || root->right == NULL)
        return -1LL;
    long long maxSum = 0;
    sumPath(root, maxSum);
    return maxSum;
}