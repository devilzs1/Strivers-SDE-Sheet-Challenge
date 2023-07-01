
// space optimised tabulation
#include <bits/stdc++.h>
int cutLogs(int k, int n)
{
    // Write your code here.
    vector<int> prev(n + 1);
    for (int i = 1; i <= n; i++)
        prev[i] = i;
    for (int i = 2; i <= k; i++)
    {
        vector<int> curr(n + 1, 0);
        curr[1] = 1;
        for (int j = 2; j <= n; j++)
        {
            int mini = INT_MAX;
            int start = 1, end = j;
            while (start <= end)
            {
                int mid = start + (end - start) / 2;
                int less = prev[mid - 1];
                int more = curr[j - mid];

                mini = min(mini, 1 + max(less, more));

                if (less < more)
                {
                    start = mid + 1;
                }
                else
                    end = mid - 1;
            }
            curr[j] = mini;
        }
        prev = curr;
    }
    return prev[n];
}


//* tabulation
//  #include<bits/stdc++.h>

// int cutLogs(int k, int n)
// {
//     // Write your code here.
//     vector<vector<int>> dp(k+1,vector<int>(n+1,0));
//     for(int i=1;i<=k;i++) dp[i][1]=1;
//     for(int i=1;i<=n;i++) dp[1][i]=i;

//     for(int i=2;i<=k;i++){
//         for(int j=2;j<=n;j++){
//             int mini = INT_MAX;
//             int start = 1, end = j;
//             while(start<=end){
//                 int mid = start + (end-start)/2;
//                 int less = dp[i-1][mid-1];
//                 int more = dp[i][j-mid];

//                 mini = min(mini, 1 + max(less,more));

//                 if(less<more){
//                     start = mid+1;
//                 }else end = mid-1;
//             }
//             dp[i][j] = mini;
//         }
//     }
//     return dp[k][n];
// }

//* recursive + memoisation
//  #include<bits/stdc++.h>

// int cut(int k,int n,vector<vector<int>>&dp){
//     if(n<=1) return n;
//     if(k==1) return n;

//     if(dp[k][n]!=-1) return dp[k][n];
//     int mini = INT_MAX;
//     int start = 1, end = n;
//     while(start<=end){
//         int mid = start + (end-start)/2;
//         int less = cut(k-1,mid-1,dp);
//         int more = cut(k,n-mid,dp);

//         mini = min(mini, 1 + max(less,more));

//         if(less<more){
//             start = mid+1;
//         }else end = mid-1;
//     }
//     return dp[k][n] = mini;
// }

// int cutLogs(int k, int n)
// {
//     // Write your code here.
//     vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
//     return cut(k,n,dp);
// }
