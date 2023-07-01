// tabulation
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<int> dp(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        dp[i] = i * price[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int len = 0; len <= n; len++)
        {
            int nottake = 0 + dp[len], take = INT_MIN;
            int rodlen = i + 1;
            if (rodlen <= len)
                take = price[i] + dp[len - rodlen];

            dp[len] = max(nottake, take);
        }
    }

    return dp[n];
}

// recursive + memoization
//  int solve(int ind, int n,vector<int>&price,vector<vector<int>>& dp){

//     if(ind == 0)
//         return n*price[0];

//     if(dp[ind][n]!=-1)
//         return dp[ind][n];

//     int nottake = 0 + solve(ind-1,n,price,dp);
//     int take = 0, len = ind+1;
//     if(len <= n)
//         take = price[ind] + solve(ind,n-len,price,dp);

//     return dp[ind][n] = max(take,nottake);
// }

// int cutRod(vector<int> &price, int n)
// {
// 	// Write your code here.
//     vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
//     return solve(n-1,n,price,dp);
// }
