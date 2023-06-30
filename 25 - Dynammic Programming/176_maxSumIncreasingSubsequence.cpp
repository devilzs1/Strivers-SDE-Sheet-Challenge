#include <bits/stdc++.h>

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    // Write your code here
    int dumbsum = 0;
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int pick = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (rack[j] > rack[i])
            {
                pick = max(pick, dp[j]);
            }
        }
        dp[i] = rack[i] + pick;
        dumbsum = max(dumbsum, dp[i]);
    }
    return dumbsum;
}

// recursive
//  #include <bits/stdc++.h>

// int solve(int ind,int prev,int n,vector<int>&rack){
// 	if(ind==n) return 0;
// 	// if(dp[ind]!=-1) return dp[ind];
// 	int notpick = 0 + solve(ind+1,prev,n,rack);
// 	int pick = 0;
// 	if(rack[ind]>prev){
// 		pick = rack[ind] + solve(ind+1,rack[ind],n,rack);
// 	}
// 	return max(pick,notpick);
// }
// int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
// {
// 	// Write your code here
// 	vector<int> dp(n+1,-1);
// 	return solve(0,-1,n,rack,dp);
// }