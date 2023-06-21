#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

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

void leftView(TreeNode<int> *temp, vector<int> &topView, int level)
{
    if (temp == NULL)
        return;
    if (topView.size() == level)
    {
        topView.push_back(temp->val);
    }

    if (temp->left)
        leftView(temp->left, topView, level + 1);
    if (temp->right)
        leftView(temp->right, topView, level - 1);
}

void rightView(TreeNode<int> *temp, vector<int> &topView, int level)
{
    if (temp == NULL)
        return;
    if (topView.size() == level)
    {
        topView.push_back(temp->val);
    }
    if (temp->right)
        rightView(temp->right, topView, level + 1);
    if (temp->left)
        rightView(temp->left, topView, level - 1);
}

vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> topView;
    if (root == NULL)
        return topView;
    int level = 0;
    leftView(root, topView, level);
    reverse(begin(topView), end(topView));
    topView.pop_back();
    level = topView.size();
    rightView(root, topView, level);

    return topView;
}