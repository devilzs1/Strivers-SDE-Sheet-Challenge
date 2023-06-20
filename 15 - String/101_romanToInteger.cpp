#include <bits/stdc++.h>
int romanToInt(string s)
{
    // Write your code here
    unordered_map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'I' && s[i + 1] == 'V')
        {
            i++;
            ans += 4;
        }
        else if (s[i] == 'I' && s[i + 1] == 'X')
        {
            i++;
            ans += 9;
        }
        else if (s[i] == 'X' && s[i + 1] == 'L')
        {
            i++;
            ans += 40;
        }
        else if (s[i] == 'X' && s[i + 1] == 'C')
        {
            i++;
            ans += 90;
        }
        else if (s[i] == 'C' && s[i + 1] == 'D')
        {
            i++;
            ans += 400;
        }
        else if (s[i] == 'C' && s[i + 1] == 'M')
        {
            i++;
            ans += 900;
        }
        else
        {
            ans += mp[s[i]];
        }
    }
    return ans;
}
