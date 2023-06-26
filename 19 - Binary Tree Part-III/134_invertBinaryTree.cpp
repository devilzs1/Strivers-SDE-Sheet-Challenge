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
bool solve(stack<TreeNode<int> *> &st, TreeNode<int> *root, TreeNode<int> *leaf)
{

    st.push(root);
    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == leaf->data)
            return true;
        else
        {
            st.pop();
            return false;
        }
    }
    if (root->left && (solve(st, root->left, leaf)))
        return true;
    if (root->right && (solve(st, root->right, leaf)))
        return true;

    st.pop();
    return false;
}

TreeNode<int> *invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
    // Write your code here.
    if (root == NULL)
        return NULL;
    stack<TreeNode<int> *> st;
    solve(st, root, leaf);
    TreeNode<int> *head = st.top();
    st.pop();
    TreeNode<int> *temp = head;
    while (!st.empty())
    {
        auto node = st.top();
        st.pop();
        if (node->left == temp)
        {
            node->left = NULL;
        }
        else
        {
            node->right = node->left;
            node->left = NULL;
        }
        temp->left = node;
        temp = node;
    }
    return head;
}
