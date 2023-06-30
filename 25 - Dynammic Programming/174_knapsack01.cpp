int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    // Write your code here
    vector<int> prev(w + 1);
    for (int i = 1; i <= n; i++)
    {
        vector<int> curr(w + 1);
        for (int j = 1; j <= w; j++)
        {
            curr[j] = prev[j];
            if (j - weights[i - 1] >= 0)
            {
                curr[j] = max(curr[j], values[i - 1] + prev[j - weights[i - 1]]);
            }
        }
        prev = curr;
    }
    return prev[w];
}