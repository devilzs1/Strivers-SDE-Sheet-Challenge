#include <bits/stdc++.h>

string solve(int n, string &s)
{
    if (n == 0)
        return s;

    string ans = "";
    int count = 1;
    char val = s[0];
    for (int i = 1; i <= s.length(); i++)
    {
        if (i == s.length())
        {
            ans += to_string(count) + val;
            break;
        }
        if (s[i] == s[i - 1])
            count++;
        else
        {
            ans += to_string(count) + val;
            val = s[i];
            count = 1;
        }
    }
    return solve(n - 1, ans);
}

string writeAsYouSpeak(int n)
{
    // Write your code here.
    string x = "1";
    return solve(n - 1, x);
}