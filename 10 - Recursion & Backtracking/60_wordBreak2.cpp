#include <bits/stdc++.h>

class Trie
{
public:
    Trie *arr[26];
    bool isEndOfWord;
    Trie()
    {
        for (int i = 0; i < 26; i++)
            arr[i] = NULL;
        isEndOfWord = false;
    }
};

void insert(string s, Trie *root)
{
    int n = s.length();
    Trie *temp = root;
    for (int i = 0; i < n; i++)
    {
        int x = s[i] - 'a';
        if (temp->arr[x] == NULL)
        {
            temp->arr[x] = new Trie();
        }
        temp = temp->arr[x];
    }
    temp->isEndOfWord = true;
}
bool search(string s, Trie *root)
{
    int n = s.length();
    Trie *temp = root;
    for (int i = 0; i < n; i++)
    {
        int x = s[i] - 'a';
        if (temp->arr[x] == NULL)
            return false;
        temp = temp->arr[x];
    }
    return temp->isEndOfWord;
}

void solve(int ind, string &s, vector<string> &wordBr, vector<string> temp, Trie *root)
{
    if (ind == s.length())
    {
        string ans = "";
        for (auto it : temp)
        {
            if (ans.length())
                ans += " " + it;
            else
                ans += it;
        }
        wordBr.push_back(ans);
        return;
    }
    for (int i = ind; i < s.length(); i++)
    {
        if (search(s.substr(ind, i - ind + 1), root))
        {
            temp.push_back(s.substr(ind, i - ind + 1));
            solve(i + 1, s, wordBr, temp, root);
            temp.pop_back();
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    Trie *root = new Trie();
    vector<string> temp, wordBr;
    for (int i = 0; i < dictionary.size(); i++)
    {
        insert(dictionary[i], root);
    }
    solve(0, s, wordBr, temp, root);

    return wordBr;
}