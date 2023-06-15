#include <bits/stdc++.h>
int findMinimumCoins(int amount)
{
    // Write your code here
    vector<int> den = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int minCoins = 0, target = amount;
    for (int i = 0; i < den.size() && target > 0; i++)
    {
        minCoins += target / den[i];
        target %= den[i];
    }
    return minCoins;
}
