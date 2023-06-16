int NthRoot(int n, int m)
{
    // Write your code here.
    if (n == 1)
        return m;
    int start = 2, end = m;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (pow(mid, n) == m)
            return mid;
        if (pow(mid, n) < m)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}