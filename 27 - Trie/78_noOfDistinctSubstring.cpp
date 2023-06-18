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

int distinctSubstring(string &word)
{
    //  Write your code here.
    Trie *root = new Trie();
    int disSubstring = 0;
    int n = word.length();
    for (int i = 0; i < n; i++)
    {
        Trie *temp = root;
        for (int j = i; j < n; j++)
        {
            int x = word[j] - 'a';
            if (temp->arr[x] == NULL)
            {
                temp->arr[x] = new Trie();
                temp->isEndOfWord = true;
                ++disSubstring;
            }
            temp = temp->arr[x];
        }
    }
    return disSubstring;
}
