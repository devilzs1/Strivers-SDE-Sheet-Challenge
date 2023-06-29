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

class BSTiterator
{
public:
    stack<int> st;

    void inorder(TreeNode<int> *root)
    {
        if (root == NULL)
            return;

        inorder(root->right);
        st.push(root->data);
        inorder(root->left);
    }
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        TreeNode<int> *temp = root;
        inorder(temp);
    }

    int next()
    {
        // write your code here
        if (!st.empty())
        {
            int nx = st.top();
            st.pop();
            return nx;
        }
        return -1;
    }

    bool hasNext()
    {
        // write your code here
        return !st.empty();
    }
};

/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/