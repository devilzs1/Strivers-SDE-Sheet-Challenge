#include <bits/stdc++.h>

int kthLargest(vector<int> &arr, int size, int K)
{
    // Write your code here.

    // min-heap
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto it : arr)
    {
        pq.push(it);
        if (pq.size() > K)
            pq.pop();
    }
    return pq.top();

    // sorting
    // sort(begin(arr),end(arr));
    // return arr[size-K];
}