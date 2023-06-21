#include <bits/stdc++.h>
/*
    template <typename T = int>
    class TreeNode
    {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if (left != NULL)
            {
                delete left;
            }
            if (right != NULL)
            {
                delete right;
            }
        }
    };
*/

void dfs(TreeNode<int> *temp, int x, bool &flag, vector<int> &path)
{
    if (temp == NULL)
        return;
    if (temp->data == x)
    {
        path.push_back(temp->data);
        flag = true;
        return;
    }
    if (!flag)
        path.push_back(temp->data);
    dfs(temp->left, x, flag, path);
    dfs(temp->right, x, flag, path);
    if (!flag)
        path.pop_back();
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
    bool flag = false;
    vector<int> path;
    dfs(root, x, flag, path);
    return path;
}
