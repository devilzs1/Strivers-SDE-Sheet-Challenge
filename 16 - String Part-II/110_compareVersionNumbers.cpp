#include <bits/stdc++.h>
int compareVersions(string a, string b)
{
    // Write your code here
    int f = a.length(), s = b.length();
    int i = 0, j = 0;
    while (i < f || j < s)
    {
        long long x = 0, y = 0;
        while (i < f && a[i] != '.')
        {
            x = x * 10 + (a[i] - '0');
            i++;
        }
        while (j < s && b[j] != '.')
        {
            y = y * 10 + (b[j] - '0');
            j++;
        }
        if (x > y)
            return 1;
        else if (x < y)
            return -1;

        i++, j++;
    }
    return 0;
}