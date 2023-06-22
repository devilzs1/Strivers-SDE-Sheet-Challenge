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
pair<int, int> diameterBinaryTree(TreeNode<int> *root)
{
    if (root == NULL)
        return {0, 0};

    pair<int, int> left = diameterBinaryTree(root->left);
    pair<int, int> right = diameterBinaryTree(root->right);

    pair<int, int> ans;
    int height = left.second + right.second + 1;
    ans.first = max({left.first, right.first, height});
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    // Write Your Code Here.
    auto it = diameterBinaryTree(root);
    return it.first - 1;
}
