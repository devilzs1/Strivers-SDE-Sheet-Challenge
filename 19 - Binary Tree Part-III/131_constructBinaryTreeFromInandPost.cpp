#include <bits/stdc++.h>

/************************************************************

   Following is the TreeNode class structure

   class TreeNode<T>
   {
   public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
   };


 ************************************************************/
TreeNode<int> *solve(vector<int> &inOrder, vector<int> &postOrder, int &index, int postorderStart,
                     int postorderEnd, int n, unordered_map<int, int> &mp)
{
    if (index < 0 || postorderStart > postorderEnd)
        return NULL;

    int element = postOrder[index--];
    TreeNode<int> *root = new TreeNode<int>(element);
    int position = mp[element];

    root->right = solve(inOrder, postOrder, index, position + 1, postorderEnd, n, mp);
    root->left = solve(inOrder, postOrder, index, postorderStart, position - 1, n, mp);

    return root;
}
TreeNode<int> *getTreeFromPostorderAndInorder(vector<int> &postOrder, vector<int> &inOrder)
{
    // Write your code here.
    int n = inOrder.size();
    int postOrderIndex = n - 1;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[inOrder[i]] = i;

    TreeNode<int> *ans = solve(inOrder, postOrder, postOrderIndex, 0, n - 1, n, mp);
    return ans;
}
