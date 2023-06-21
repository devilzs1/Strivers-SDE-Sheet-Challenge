#include <bits/stdc++.h>
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> preorder;
    TreeNode *temp = root;
    while (temp)
    {
        if (temp->left == NULL)
        {
            preorder.push_back(temp->data);
            temp = temp->right;
        }
        else
        {
            TreeNode *next = temp->left;
            while (next->right && next->right != temp)
            {
                next = next->right;
            }
            if (next->right == NULL)
            {
                next->right = temp;
                preorder.push_back(temp->data);
                temp = temp->left;
            }
            else
            {
                next->right = NULL;
                temp = temp->right;
            }
        }
    }
    return preorder;
}