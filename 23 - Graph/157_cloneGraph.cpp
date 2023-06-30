#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
void solve(graphNode* clone, graphNode* node, unordered_map<graphNode*,graphNode*>&mp){

	for(auto it: node->neighbours){
		if(mp.find(it)==mp.end()){
			graphNode* currClone = new graphNode(it->data);
			clone->neighbours.push_back(currClone);
			mp[it] = currClone;
			solve(currClone,it,mp);
		}else{
			clone->neighbours.push_back(mp[it]);
		}
	}
}

graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
	if(node==NULL) return node;

	graphNode* clone = new graphNode(node->data);
	unordered_map<graphNode*,graphNode*> mp;
	mp[node] = clone;
	solve(clone,node,mp);
	return clone;
}