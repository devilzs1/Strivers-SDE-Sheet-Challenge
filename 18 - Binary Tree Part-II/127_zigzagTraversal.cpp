#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> zigzag;
    if (root == NULL)
        return zigzag;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    bool rev = true;
    while (!q.empty())
    {
        int sz = q.size();
        vector<int> temp(sz);
        for (int i = 0; i < sz; i++)
        {
            auto node = q.front();
            q.pop();
            int ind = rev ? i : sz - i - 1;
            temp[ind] = node->data;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        rev = !rev;
        for (auto it : temp)
            zigzag.push_back(it);
    }
    return zigzag;
}
