#include <bits/stdc++.h>

int arr[100001];
int size = 0;
void minHeapify(int i)
{

    int small = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && arr[left] < arr[small])
        small = left;
    if (right < size && arr[right] < arr[small])
        small = right;

    if (small != i)
    {
        swap(arr[small], arr[i]);
        minHeapify(small);
    }
}
void insert(int val)
{
    arr[size] = val;
    ++size;
    for (int i = size / 2 + 1; i >= 0; i--)
    {
        minHeapify(i);
    }
}

int removeInsert()
{
    int mini = arr[0];
    swap(arr[0], arr[size - 1]);
    --size;
    minHeapify(0);
    return mini;
}

vector<int> minHeap(int n, vector<vector<int>> &q)
{
    // Write your code here.
    vector<int> heap;
    size = 0;
    for (int i = 0; i < n; i++)
    {
        int type = q[i][0];
        if (type == 0)
            insert(q[i][1]);
        else
            heap.push_back(removeInsert());
    }
    return heap;
}
