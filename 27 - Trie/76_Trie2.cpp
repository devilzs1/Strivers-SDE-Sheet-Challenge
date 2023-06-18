#include <bits/stdc++.h>
class Trie
{
    class Node
    {
    public:
        Node *arr[26];
        int equalWord, prefixWord;
        bool isEndOfWord;
        Node()
        {
            for (int i = 0; i < 26; i++)
                arr[i] = NULL;
            equalWord = 0;
            prefixWord = 0;
            isEndOfWord = false;
        }
    };
    Node *root;

public:
    Trie()
    {
        // Write your code here.
        root = new Node();
    }

    void insert(string &word)
    {
        // Write your code here.
        Node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            int x = word[i] - 'a';
            if (temp->arr[x] == NULL)
                temp->arr[x] = new Node();
            temp = temp->arr[x];
            temp->prefixWord++;
        }
        temp->equalWord++;
    }

    int countWordsEqualTo(string &word)
    {
        // Write your code here.
        Node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            int x = word[i] - 'a';
            if (temp->arr[x] == NULL)
                return 0;
            temp = temp->arr[x];
        }
        return temp->equalWord;
    }

    int countWordsStartingWith(string &word)
    {
        // Write your code here.
        Node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            int x = word[i] - 'a';
            if (temp->arr[x] == NULL)
                return 0;
            temp = temp->arr[x];
        }
        return temp->prefixWord;
    }

    void erase(string &word)
    {
        // Write your code here.
        Node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            int x = word[i] - 'a';
            if (temp->arr[x] == NULL)
                return;
            temp = temp->arr[x];
            temp->prefixWord--;
        }
        temp->equalWord--;
    }
};
