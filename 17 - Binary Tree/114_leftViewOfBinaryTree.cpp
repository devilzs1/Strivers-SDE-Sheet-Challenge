#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void trav(TreeNode<int> *temp, vector<int> &leftview, int level)
{
    if (temp == NULL)
        return;
    if (level == leftview.size())
        leftview.push_back(temp->data);

    if (temp->left)
        trav(temp->left, leftview, level + 1);
    if (temp->right)
        trav(temp->right, leftview, level + 1);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    TreeNode<int> *temp = root;
    vector<int> leftview;
    trav(temp, leftview, 0);
    return leftview;
}