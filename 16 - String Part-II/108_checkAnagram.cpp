#include <bits/stdc++.h>
bool areAnagram(string &str1, string &str2)
{
    // Write your code here.
    vector<int> first(26), second(26);
    int f = str1.length(), s = str2.length();
    if (f != s)
        return false;
    for (int i = 0; i < f; i++)
    {
        first[str1[i] - 'a']++;
        second[str2[i] - 'a']++;
    }
    return (first == second);
}