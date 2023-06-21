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

void trav(TreeNode *temp, vector<int> &postorder)
{
    if (temp == NULL)
        return;
    trav(temp->left, postorder);
    trav(temp->right, postorder);
    postorder.push_back(temp->data);
}
vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> postorder;
    TreeNode *temp = root;
    trav(temp, postorder);
    return postorder;
}