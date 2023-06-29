#include <bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n)
{

    // Write your code here
    vector<int> median;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++)
    {

        int minLen = minHeap.size(), maxLen = maxHeap.size();
        if (minLen == maxLen)
        {
            if (maxLen == 0)
            {
                maxHeap.push(arr[i]);
            }
            else
            {
                if (arr[i] >= maxHeap.top())
                    minHeap.push(arr[i]);
                else
                    maxHeap.push(arr[i]);
            }
        }
        else
        {
            if (maxLen > minLen)
            {
                if (arr[i] > maxHeap.top())
                    minHeap.push(arr[i]);
                else
                {
                    int x = maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(arr[i]);
                    minHeap.push(x);
                }
            }
            else
            {
                if (arr[i] <= minHeap.top())
                    maxHeap.push(arr[i]);
                else
                {
                    int x = minHeap.top();
                    minHeap.pop();
                    minHeap.push(arr[i]);
                    maxHeap.push(x);
                }
            }
        }

        minLen = minHeap.size(), maxLen = maxHeap.size();
        if (minLen == maxLen)
        {
            median.push_back((minHeap.top() + maxHeap.top()) / 2);
        }
        else
        {
            if (minLen > maxLen)
                median.push_back(minHeap.top());
            else
                median.push_back(maxHeap.top());
        }
    }
    return median;
}
