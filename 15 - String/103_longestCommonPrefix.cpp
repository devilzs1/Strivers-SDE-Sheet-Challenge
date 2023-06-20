string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    bool flag = true;
    string comPref = "";
    int j = 0;
    while (flag)
    {
        for (int i = 0; i < n; i++)
        {
            if (j < arr[i].length() && arr[i][j] == arr[0][j])
                continue;
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
            comPref += arr[0][j];
        j++;
    }
    return comPref;
}
