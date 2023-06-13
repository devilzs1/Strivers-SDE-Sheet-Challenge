bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int m = mat.size(), n = mat[0].size();
    int start = 0, end = m * n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int x = mat[mid / n][mid % n];
        if (x == target)
            return true;
        if (x < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return false;
}