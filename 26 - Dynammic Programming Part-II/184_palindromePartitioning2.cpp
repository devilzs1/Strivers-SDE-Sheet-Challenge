#include <bits/stdc++.h>

bool isPal(int start, int end, string &s)
{
    while (start <= end)
    {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int palindromePartitioning(string str)
{
    int n = str.length();
    vector<int> dp(n + 1);
    for (int i = n - 1; i >= 0; i--)
    {
        int mini = INT_MAX;
        for (int j = i; j < str.length(); j++)
        {
            int cost = 0;
            if (isPal(i, j, str))
            {
                cost = 1 + dp[j + 1];
                mini = min(cost, mini);
            }
        }
        dp[i] = mini;
    }
    return dp[0] - 1;
}

// recursive
//  #include <bits/stdc++.h>

// bool isPal(int start, int end,string &s){
//     while(start<=end){
//         if(s[start]!=s[end]) return false;
//         start++; end--;
//     }
//     return true;
// }

// int solve(int ind,string &str){
//     if(ind==str.length()) return 0;

//     int mini = INT_MAX;
//     for(int j=ind;j<str.length();j++){
//         int cost = 0;
//         if(isPal(ind,j,str)){
//             cost = 1 + solve(j+1,str);
//             mini = min(cost,mini);
//         }
//     }
//     return mini;
// }
// int palindromePartitioning(string str) {
//     // Write your code here
//     return solve(0,str)-1;
// }
