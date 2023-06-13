#include <bits/stdc++.h>

long long int cal(int i, int j, vector<vector<long long int>> &pascal)
{
    int m = pascal[i].size();
    if (i < 0 || j < 0 || j >= m)
        return 0;
    return pascal[i][j];
}

vector<vector<long long int>> printPascal(int n)
{
    // Write your code here.
    vector<vector<long long int>> pascal;
    vector<long long int> temp = {1LL};
    pascal.push_back(temp);

    for (int i = 1; i < n; i++)
    {
        temp.resize(i + 1);
        for (int j = 0; j < i + 1; j++)
        {
            temp[j] = cal(i - 1, j, pascal) + cal(i - 1, j - 1, pascal);
        }
        pascal.push_back(temp);
    }
    return pascal;
}
