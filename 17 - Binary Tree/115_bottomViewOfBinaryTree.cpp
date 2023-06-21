#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> *root)
{

    // Write your code here.
    vector<int> bottom;

    if (root == NULL)
        return bottom;

    map<int, int> bottomNode;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        BinaryTreeNode<int> *node = temp.first;
        int pos = temp.second;
        bottomNode[pos] = node->data;

        if (node->left)
            q.push(make_pair(node->left, pos - 1));
        if (node->right)
            q.push(make_pair(node->right, pos + 1));
    }

    for (auto it : bottomNode)
        bottom.push_back(it.second);

    return bottom;
}
