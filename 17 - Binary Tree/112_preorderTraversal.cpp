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

void trav(TreeNode *temp, vector<int> &preorder)
{
    if (temp == NULL)
        return;
    preorder.push_back(temp->data);
    trav(temp->left, preorder);
    trav(temp->right, preorder);
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> preorder;
    TreeNode *temp = root;
    trav(temp, preorder);
    return preorder;
}