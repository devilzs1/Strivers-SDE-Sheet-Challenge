#include <bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    // Write your code here.
    // Time complexity: O(nlogn) Space Complexity: O(1)
    sort(begin(arr), end(arr));
    return {arr[k - 1], arr[n - k]};

    // How this code time Complexity is O(N^2), according to me at max it is O(n*logn)??
    // priority_queue<int> pq;
    // int small = 0, large = 0, i=1;
    // for(int i=0;i<n;i++) pq.push(arr[i]);
    // while(!pq.empty()){
    // 	int it = pq.top();
    // 	pq.pop();
    // 	if(i==k) large = it;
    // 	if(i==n-k+1) small = it;
    // 	i++;
    // }
    // return {small,large};
}