
int upperBound(int x, vector<int> &temp)
{
    int start = 0, end = temp.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (temp[mid] <= x)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return start;
}

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int m = matrix.size(), n = matrix[0].size();
    int tot = n * m;
    int start = 1, end = 1e5;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        int lessNumber = 0;
        for (int i = 0; i < m; i++)
        {
            lessNumber += upperBound(mid, matrix[i]);
        }
        if (lessNumber <= tot / 2)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return start;
}