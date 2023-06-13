#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices)
{
    // Write your code here.
    int profit = 0, mini = INT_MAX;
    int n = prices.size();
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, prices[i]);
        profit = max(profit, prices[i] - mini);
    }
    return profit;
}