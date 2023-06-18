/*
    Your Node object will be instantiated and called as such:
    Node* obj = new Node();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class Trie
{
    class Node
    {
    public:
        Node *arr[26];
        bool isEndOfWord;
        Node()
        {
            for (int i = 0; i < 26; i++)
                arr[i] = NULL;
            isEndOfWord = false;
        }
    };
    Node *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            int x = word[i] - 'a';
            if (temp->arr[x] == NULL)
            {
                temp->arr[x] = new Node();
            }
            temp = temp->arr[x];
        }
        temp->isEndOfWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            int x = word[i] - 'a';
            if (temp->arr[x] == NULL)
                return false;
            temp = temp->arr[x];
        }
        return temp->isEndOfWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Node *temp = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            int x = prefix[i] - 'a';
            if (temp->arr[x] == NULL)
                return false;
            temp = temp->arr[x];
        }
        return true;
    }
};