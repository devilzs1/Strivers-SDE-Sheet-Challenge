#include <bits/stdc++.h>
/************************************************************
    Following is the Binary Search Tree node structure

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int> *LCAinaBST(TreeNode<int> *root, TreeNode<int> *P, TreeNode<int> *Q)
{
    // Write your code here

    if (root == NULL)
        return NULL;

    int x = root->data;
    if (x > P->data && x > Q->data)
        return LCAinaBST(root->left, P, Q);
    if (x < P->data && x < Q->data)
        return LCAinaBST(root->right, P, Q);

    return root;
}
// TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
// {
// 	// Write your code here

//     if(root==NULL) return NULL;

//     if(root->data == P->data || root->data == Q->data) return root;

//     TreeNode<int>* left = LCAinaBST(root->left,P,Q);
//     TreeNode<int>* right = LCAinaBST(root->right,P,Q);

//     if(left && right) return root;
//     if(left && !right) return left;
//     if(!left && right) return right;
//     return NULL;
// }
