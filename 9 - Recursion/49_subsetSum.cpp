#include <bits/stdc++.h>

void solve(int ind, int val, vector<int> &num, vector<int> &sum)
{
    if (ind == num.size())
    {
        sum.push_back(val);
        return;
    }
    solve(ind + 1, val, num, sum);
    solve(ind + 1, val + num[ind], num, sum);
}
vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> sum;
    solve(0, 0, num, sum);
    sort(begin(sum), end(sum));
    return sum;
}