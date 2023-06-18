#include <bits/stdc++.h>

class Trie
{
public:
    Trie *arr[2];
    bool isEndOfWord;
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
    temp->isEndOfWord = true;
}
int solve(int val, Trie *root)
{
    Trie *temp = root;
    int maxValue = 0;
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
int maximumXor(vector<int> A)
{
    // Write your code here.
    Trie *root = new Trie();
    int n = A.size();
    for (int i = 0; i < n; i++)
        insert(A[i], root);

    int maxXor = 0;
    for (int i = 0; i < n; i++)
    {
        maxXor = max(maxXor, solve(A[i], root));
    }

    return maxXor;
}