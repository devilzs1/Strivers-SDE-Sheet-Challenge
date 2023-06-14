int longestSubSeg(vector<int> &arr, int n, int k)
{
    // Write your code here.
    int maxLen = 0;
    int start = 0, zero = 0;
    for (int end = 0; end < n; end++)
    {
        if (arr[end] == 0)
            zero++;
        if (zero > k)
        {
            while (arr[start] != 0)
                start++;
            start++;
            zero--;
        }
        maxLen = max(maxLen, end - start + 1);
    }
    return maxLen;
}
