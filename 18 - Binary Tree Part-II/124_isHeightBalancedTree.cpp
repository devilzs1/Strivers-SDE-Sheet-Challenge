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

pair<bool,int> trav(BinaryTreeNode<int>* root){
    if(root==NULL) return {true,0};

    pair<bool,int> check;
    pair<bool,int> left = trav(root->left);
    pair<bool,int> right = trav(root->right);

    check.second = max(left.second, right.second) + 1;
    if(abs(left.second-right.second)<=1 && left.first && right.first) check.first = true;
    else check.first = false;

    return check;
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    return trav(root).first;
}