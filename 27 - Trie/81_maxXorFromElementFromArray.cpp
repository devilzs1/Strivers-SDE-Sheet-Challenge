#include <bits/stdc++.h>

class Trie
{
public:
    Trie *arr[2];
    bool isEndOfWord = true;
    Trie()
    {
        for (int i = 0; i < 2; i++)
            arr[i] = NULL;
        isEndOfWord = false;
    }
};

void insert(int val, Trie *root)
{
    Trie *temp = root;
    for (int i = 31; i >= 0; i--)
    {
        int x = (val >> i) & 1;
        if (temp->arr[x] == NULL)
            temp->arr[x] = new Trie();
        temp = temp->arr[x];
    }
}

int solve(int val, Trie *root)
{
    int maxValue = 0;
    Trie *temp = root;
    for (int i = 31; i >= 0; i--)
    {
        int x = (val >> i) & 1;
        if (temp->arr[1 - x] == NULL)
            temp = temp->arr[x];
        else
        {
            maxValue = maxValue | (1 << i);
            temp = temp->arr[1 - x];
        }
    }
    return maxValue;
}

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    //	Write your coode here.
    Trie *root = new Trie();
    sort(begin(arr), end(arr));
    int n = arr.size(), m = queries.size();
    vector<pair<int, pair<int, int>>> temp;
    for (int i = 0; i < m; i++)
    {
        temp.push_back({queries[i][1], {queries[i][0], i}});
    }
    sort(begin(temp), end(temp));
    vector<int> xorAns(m, -1);
    int ind = 0;
    for (int i = 0; i < m; i++)
    {
        int val = temp[i].second.first, x = temp[i].first, index = temp[i].second.second;
        while (ind < n && arr[ind] <= x)
        {
            insert(arr[ind], root);
            ind++;
        }
        if (ind > 0)
            xorAns[index] = solve(val, root);
    }
    return xorAns;
}