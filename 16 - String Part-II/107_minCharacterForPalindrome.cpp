
int minCharsforPalindrome(string str)
{
    // Write your code here.
    int n = str.length();
    int start = 0, end = n - 1;
    int last = n - 1;
    while (start <= end)
    {
        if (str[start] == str[end])
        {
            start++;
            end--;
        }
        else
        {
            start = 0;
            last--;
            end = last;
        }
    }
    return n - last - 1;
}
