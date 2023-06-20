
string findPal(int i, int j, string &str)
{
    int n = str.length();
    while (i >= 0 && j < n && str[i] == str[j])
    {
        i--;
        j++;
    }
    return str.substr(i + 1, j - i - 1);
}

string longestPalinSubstring(string str)
{
    // Write your code here.
    int n = str.length();
    string palin = "";
    for (int i = 0; i < n; i++)
    {
        string temp = findPal(i, i, str);
        if (temp.length() > palin.length())
            palin = temp;
        temp = findPal(i, i + 1, str);
        if (temp.length() > palin.length())
            palin = temp;
    }
    return palin;
}