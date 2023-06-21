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

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if (root == NULL)
        return 0;
    int maxWidth = 0, currWidth = 0;
    queue<TreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        if (node == NULL)
        {
            maxWidth = max(maxWidth, currWidth);
            currWidth = 0;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            if (node->left)
            {
                currWidth++;
                q.push(node->left);
            }
            if (node->right)
            {
                currWidth++;
                q.push(node->right);
            }
        }
    }
    return maxWidth;
}