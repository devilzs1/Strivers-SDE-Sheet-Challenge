#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure

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

class Node
{
public:
    int mx, mn, lsize;
    Node(int sz, int mxval, int mnval)
    {
        lsize = sz;
        mx = mxval;
        mn = mnval;
    }
};

Node solve(TreeNode<int> *root)
{

    if (root == NULL)
        return Node(0, INT_MIN, INT_MAX);

    auto left = solve(root->left);
    auto right = solve(root->right);

    if (left.mx < root->data && root->data < right.mn)
    {
        int mini = min(left.mn, root->data);
        int maxi = max(right.mx, root->data);
        int sz = left.lsize + right.lsize + 1;
        return Node(sz, maxi, mini);
    }
    return Node(max(left.lsize, right.lsize), INT_MAX, INT_MIN);
}

int largestBST(TreeNode<int> *root)
{
    // Write your code here.
    Node ans = solve(root);
    return ans.lsize;
}
