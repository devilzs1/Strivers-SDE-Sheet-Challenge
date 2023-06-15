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
void solve(int ind, string &s, vector<vector<string>> &part,
           vector<string> &temp)
{
    if (ind == s.length())
    {
        part.push_back(temp);
        return;
    }
    for (int i = ind; i < s.length(); i++)
    {
        if (isPal(ind, i, s))
        {
            temp.push_back(s.substr(ind, (i - ind) + 1));
            solve(i + 1, s, part, temp);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s)
{
    // Write your code here.
    vector<vector<string>> part;
    vector<string> temp;
    solve(0, s, part, temp);
    return part;
}