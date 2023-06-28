#include <bits/stdc++.h>
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
bool solve(BinaryTreeNode<int> *root, int k, unordered_map<int, int> &mp)
{
    if (root == NULL)
        return false;

    if (mp.find(k - root->data) != mp.end())
    {
        return true;
    }
    mp[root->data]++;
    return (solve(root->left, k, mp) || solve(root->right, k, mp));
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    unordered_map<int, int> mp;
    return solve(root, k, mp);
}