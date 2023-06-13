#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n)
{
    // Write your code here.
    string flag = "No";
    unordered_map<int, pair<int, int>> mp;
    for (int i = 0; i < n - 1; i++)
    {
        bool check = false;
        for (int j = i + 1; j < n; j++)
        {
            int x = target - (arr[i] + arr[j]);
            if (mp.find(x) != mp.end())
            {
                auto it = mp[x];
                if (it.first != i && it.second != j &&
                    it.first != j && it.second != i)
                {
                    check = true;
                    flag = "Yes";
                    break;
                }
            }
            mp[arr[i] + arr[j]] = make_pair(i, j);
        }
        if (check)
            break;
    }

    return flag;
}
