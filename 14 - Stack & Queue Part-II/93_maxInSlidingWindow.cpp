#include <bits/stdc++.h>
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    deque<int> dq;
    vector<int> winMax;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        while (!dq.empty() && dq.front() == i - k)
            dq.pop_front();
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();

        dq.push_back(i);
        if (i > k - 2)
            winMax.push_back(nums[dq.front()]);
    }
    return winMax;
}