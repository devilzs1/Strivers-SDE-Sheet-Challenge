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

void trav(TreeNode *temp, vector<int> &inorder)
{
    if (temp == NULL)
        return;
    trav(temp->left, inorder);
    inorder.push_back(temp->data);
    trav(temp->right, inorder);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> inorder;
    TreeNode *temp = root;
    trav(temp, inorder);
    return inorder;
}