#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m)
{
    // Write your code here.
    int result = 1;
    while (n)
    {
        if (n & 1)
            result = (1ll * result * x) % m;
        x = (1ll * x * x) % m;
        n >>= 1;
    }
    return result;
}