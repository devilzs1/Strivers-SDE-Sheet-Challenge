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

void floorBst(TreeNode<int> *root, int X, int &mini, int &fl)
{
    if (root == NULL)
        return;

    if (root->val >= mini && root->val <= X)
    {
        mini = max(mini, root->val);
        fl = root->val;
        floorBst(root->right, X, mini, fl);
    }
    else
    {
        floorBst(root->left, X, mini, fl);
    }
}

int floorInBST(TreeNode<int> *root, int X)
{
    // Write your code here.
    int fl = -1, mini = INT_MIN;
    floorBst(root, X, mini, fl);
    return fl;
}