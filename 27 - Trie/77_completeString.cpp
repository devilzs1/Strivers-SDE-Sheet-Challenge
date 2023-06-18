#include <bits/stdc++.h>

class Trie
{
public:
    Trie *arr[26];
    bool isEndOfWord;
    Trie()
    {
        for (int i = 0; i < 26; i++)
        {
            arr[i] = NULL;
        }
        isEndOfWord = false;
    }
};

void insert(string &s, Trie *root)
{
    Trie *temp = root;
    for (int i = 0; i < s.length(); i++)
    {
        int x = s[i] - 'a';
        if (temp->arr[x] == NULL)
            temp->arr[x] = new Trie();
        temp = temp->arr[x];
    }
    temp->isEndOfWord = true;
}
string search(string &s, Trie *root)
{
    Trie *temp = root;
    int i = 0;
    for (; i < s.length(); i++)
    {
        int x = s[i] - 'a';
        if (temp->arr[x] == NULL)
            return "";
        temp = temp->arr[x];
        if (temp->isEndOfWord == false)
            return "";
    }
    return s;
}

string completeString(int n, vector<string> &a)
{
    // Write your code here.
    Trie *root = new Trie();
    for (int i = 0; i < n; i++)
    {
        insert(a[i], root);
    }
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        string temp = search(a[i], root);
        int len = temp.length();
        if (len > ans.length())
            ans = temp;
        else if (len == ans.length())
            ans = min(ans, temp);
    }
    if (ans.length())
        return ans;
    return "None";
}