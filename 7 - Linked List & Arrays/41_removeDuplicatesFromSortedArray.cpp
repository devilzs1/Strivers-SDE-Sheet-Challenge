int removeDuplicates(vector<int> &arr, int n)
{
    // Write your code here.
    int maxLen = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
            continue;

        maxLen++;
    }
    return maxLen;
}