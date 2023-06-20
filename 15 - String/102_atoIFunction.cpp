#include <bits/stdc++.h>
int atoi(string str)
{
    // Write your code here.
    int n = str.length(), sign = 1;
    if (str[0] == '-')
        sign = -1;
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            int x = str[i] - '0';
            num = num * 10 + x;
        }
    }
    num *= sign;
    return num;
}