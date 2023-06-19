// #include <bits/stdc++.h> 
// // Implement class for minStack.
// class minStack
// {
// 	// Write your code here.
// 	stack<pair<int,int>> mst;
// 	public:
// 		// Constructor
// 		minStack() 
// 		{ 
// 			// Write your code here.
// 			while(!mst.empty()) mst.pop();

// 		}
		
// 		// Function to add another element equal to num at the top of stack.
// 		void push(int num)
// 		{
// 			// Write your code here.
// 			if(mst.empty()){
// 				mst.push({num,num});
// 			}else if(mst.top().second<num){
// 				mst.push({num,mst.top().second});
// 			}else{
// 				mst.push({num,num});
// 			}

// 		}
		
// 		// Function to remove the top element of the stack.
// 		int pop()
// 		{
// 			// Write your code here.
// 			if(mst.empty()) return -1;
// 			int val = mst.top().first;
// 			mst.pop();
// 			return val;
// 		}
		
// 		// Function to return the top element of stack if it is present. Otherwise return -1.
// 		int top()
// 		{
// 			// Write your code here.
// 			if(mst.empty()) return -1;
// 			int val = mst.top().first;
// 			return val;

// 		}
		
// 		// Function to return minimum element of stack if it is present. Otherwise return -1.
// 		int getMin()
// 		{
// 			// Write your code here.
// 			if(mst.empty()) return -1;
// 			return mst.top().second;
// 		}
// };


#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	stack<int> mst;
	int mini;
	public:
		// Constructor
		minStack() 
		{ 
			// Write your code here.
			mini = INT_MAX;
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			int val = num;
			if(mst.empty()){
				mini = val;
				mst.push(val);
			}else{
				if(val<mini){
					mst.push(2*val - mini);
					mini = val;
				}else{
					mst.push(val);
				}
			}

		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
			if(mst.empty()) return -1;
			int val = mst.top();
			mst.pop();
			if(val<mini){
				int temp = mini;
				mini = 2*mini - val;
				return temp;
			}
			return val;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(mst.empty()) return -1;
			int val = mst.top();
			if(val<mini) return mini;
			return val;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			if(mst.empty()) return -1;
			return mini;
		}
};