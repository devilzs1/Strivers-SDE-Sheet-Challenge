#include <bits/stdc++.h>

void solve(int ind, string s, vector<string> &permut)
{
    if (ind + 1 == s.length())
    {
        permut.push_back(s);
        return;
    }
    for (int i = ind; i < s.length(); i++)
    {
        swap(s[ind], s[i]);
        solve(ind + 1, s, permut);
        swap(s[ind], s[i]);
    }
}
vector<string> findPermutations(string &s)
{
    // Write your code here.
    vector<string> permut;
    solve(0, s, permut);
    return permut;
}