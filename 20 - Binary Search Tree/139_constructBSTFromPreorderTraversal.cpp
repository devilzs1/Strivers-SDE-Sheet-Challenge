#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/

TreeNode<int> *solve(int &ind, int prev, vector<int> &preOrder)
{
    if (ind == preOrder.size() || preOrder[ind] > prev)
    {
        return NULL;
    }

    int x = preOrder[ind++];
    TreeNode<int> *node = new TreeNode<int>(x);
    node->left = solve(ind, x, preOrder);
    node->right = solve(ind, prev, preOrder);

    return node;
}

TreeNode<int> *preOrderTree(vector<int> &preOrder)
{
    // Write your code here.
    int x = preOrder[0], ind = 0;
    return solve(ind, INT_MAX, preOrder);
}