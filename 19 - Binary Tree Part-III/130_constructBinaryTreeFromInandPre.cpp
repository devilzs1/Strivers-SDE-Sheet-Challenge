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
TreeNode<int>* solve(vector<int>&inorder,vector<int>&preorder, int &index,
 int inorderStart, int inorderEnd, int n,unordered_map<int,int>& mp)
{
    if (index >= n || inorderStart > inorderEnd)
        return NULL;

    // create a root node for element
    int element = preorder[index++];
    TreeNode<int>* root = new TreeNode<int>(element);
    int position = mp[element];

    root->left = solve(inorder, preorder, index, inorderStart, position - 1, n,mp);
    root->right = solve(inorder, preorder, index, position + 1, inorderEnd, n,mp);

    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
        unordered_map<int,int> mp;
        int n = inorder.size();
        for(int i=0;i<n;i++) mp[inorder[i]] = i;
        int preOrderIndex = 0;
        TreeNode<int>* ans = solve(inorder, preorder, preOrderIndex, 0, n - 1, n,mp);
        return ans;
}