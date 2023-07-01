#include <bits/stdc++.h>

struct Node
{
    int left, right, height;
    Node(int l, int r, int ht)
    {
        left = l;
        right = r;
        height = ht;
    }
};

int heightOfTheTree(vector<int> &inorder, vector<int> &levelOrder, int N)
{
    // Write your code here.
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;
    queue<Node> q;
    q.push(Node(0, N - 1, 0));
    int maxHeight = 0;
    for (int i = 0; i < N; i++)
    {
        int index = mp[levelOrder[i]];
        auto node = q.front();
        q.pop();

        maxHeight = max(maxHeight, node.height);
        if (index > node.left)
        {
            q.push(Node(node.left, index - 1, node.height + 1));
        }
        if (index < node.right)
        {
            q.push(Node(index + 1, node.right, node.height + 1));
        }
    }
    return maxHeight;
}

// recursive
// #include <bits/stdc++.h>

// void solve(int inStart,int inEnd,int ht,int &maxHeight,vector<int>&inorder,
// 	unordered_map<int,int>&mp){
// 	if(inStart>inEnd) return;

// 	int index = inStart;
// 	for(int i=inStart+1;i<=inEnd;i++){
// 		if(mp[inorder[i]]<mp[inorder[index]]) index = i;
// 	}
// 	if(inStart==inEnd) return;
// 	maxHeight = max(maxHeight,1+ht);
// 	solve(inStart,index-1,ht+1,maxHeight,inorder,mp);
// 	solve(index+1,inEnd,ht+1,maxHeight,inorder,mp);

// }
// int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
// 	// Write your code here.
// 	unordered_map<int,int> mp;
// 	for(int i=0;i<N;i++) mp[levelOrder[i]]=i;
// 	int maxHeight = 0;
// 	solve(0,N-1,0,maxHeight,inorder,mp);
// 	return maxHeight;
// }
