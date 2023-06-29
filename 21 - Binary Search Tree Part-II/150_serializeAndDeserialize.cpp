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
#include <bits/stdc++.h>
string serializeTree(TreeNode<int> *root)
{
    //    Write your code here for serializing the tree
    string serial = "";
    if (root == NULL)
        return serial;
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();

        if (node == NULL)
            serial += "@,";
        else
        {
            serial += to_string(node->data) + ",";
            q.push(node->left);
            q.push(node->right);
        }
    }
    return serial;
}

TreeNode<int> *deserializeTree(string &serialized)
{
    //    Write your code here for deserializing the tree

    if (serialized.length() == 0)
        return NULL;

    stringstream des(serialized);
    string temp;
    getline(des, temp, ',');
    TreeNode<int> *root = new TreeNode<int>(stoi(temp));
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        getline(des, temp, ',');
        if (temp == "@")
        {
            node->left = NULL;
        }
        else
        {
            TreeNode<int> *x = new TreeNode<int>(stoi(temp));
            node->left = x;
            q.push(x);
        }
        getline(des, temp, ',');
        if (temp == "@")
            node->right = NULL;
        else
        {
            TreeNode<int> *y = new TreeNode<int>(stoi(temp));
            node->right = y;
            q.push(y);
        }
    }
    return root;
}
