#include <bits/stdc++.h>

void findMedian(int *arr, int n)
{
    // Write your code here
    if (n == 0)
        return;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    for (int i = 0; i < n; i++)
    {
        int minLen = minHeap.size(), maxLen = maxHeap.size();
        if (minLen == maxLen)
        {
            if (minLen == 0)
            {
                minHeap.push(arr[i]);
            }
            else if (arr[i] < maxHeap.top())
                maxHeap.push(arr[i]);
            else
                minHeap.push(arr[i]);
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
                    minHeap.push(x);
                    maxHeap.push(arr[i]);
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
                    maxHeap.push(x);
                    minHeap.push(arr[i]);
                }
            }
        }

        // find median
        minLen = minHeap.size(), maxLen = maxHeap.size();
        if (minLen == maxLen)
            cout << (minHeap.top() + maxHeap.top()) / 2 << " ";
        else
        {
            if (minLen > maxLen)
                cout << minHeap.top() << " ";
            else
                cout << maxHeap.top() << " ";
        }
    }
    return;
}