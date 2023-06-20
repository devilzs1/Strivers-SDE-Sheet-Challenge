#include <bits/stdc++.h>
vector<int> prefix_function(string s)
{
    int n = s.length();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];

        if (s[i] == s[j])
            j++;

        pi[i] = j;
    }
    return pi;
}
bool findPattern(string p, string s)
{
    // Write your code here.
    vector<int> pref = prefix_function(p);
    int i = 0, j = 0;
    while (i < s.length())
    {
        if (s[i] == p[j])
        {
            j++;
            i++;
        }
        else
        {
            if (j != 0)
            {
                j = pref[j - 1];
            }
            else
                i++;
        }

        if (j == p.size())
            return true;
        
    }
    return false;
}