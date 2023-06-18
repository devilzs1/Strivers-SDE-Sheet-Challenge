#include <bits/stdc++.h>

void solve(int ind,vector<int>&v,vector<vector<int>>&powerSet,vector<int>temp){
    if(ind==v.size()){
        powerSet.push_back(temp);
        return;
    }
    solve(ind+1,v,powerSet,temp);

    temp.push_back(v[ind]);
    solve(ind+1,v,powerSet,temp);
    temp.pop_back();
}
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    vector<vector<int>> powerSet;
    solve(0,v,powerSet,{});
    return powerSet;
}