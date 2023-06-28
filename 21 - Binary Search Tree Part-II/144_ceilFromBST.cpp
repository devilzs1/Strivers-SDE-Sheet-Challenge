#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

void solve(BinaryTreeNode<int> *node, int x, int &ans)
{
    if (node == NULL)
        return;
    if (node->data >= x)
    {
        ans = node->data;
        solve(node->left, x, ans);
    }
    else
    {
        solve(node->right, x, ans);
    }
}

int findCeil(BinaryTreeNode<int> *node, int x)
{
    // Write your code here.
    int ans = -1;
    solve(node, x, ans);
    return ans;
}