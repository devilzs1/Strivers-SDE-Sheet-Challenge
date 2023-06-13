#include <bits/stdc++.h>
int uniqueSubstrings(string input)
{
    // Write your code here
    vector<int> freq(128);
    int n = input.length(), left = 0, maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        ++freq[input[i]];
        while (freq[input[i]] > 1)
        {
            freq[input[left++]]--;
        }
        maxLen = max(maxLen, i - left + 1);
    }
    return maxLen;
}
