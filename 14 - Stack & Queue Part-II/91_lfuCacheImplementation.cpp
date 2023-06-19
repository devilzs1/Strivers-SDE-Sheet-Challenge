#include <bits/stdc++.h>
class LFUCache
{
    class Node
    {
    public:
        int key, val, count;
        Node *next, *prev;
        Node(int k, int d)
        {
            key = k;
            val = d;
            count = 1;
        }
    };
    class List
    {
    public:
        int size;
        Node *head;
        Node *tail;
        List()
        {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void addNode(Node *nNode)
        {
            Node *temp = head->next;
            nNode->next = temp;
            nNode->prev = head;
            head->next = nNode;
            temp->prev = nNode;
            ++size;
        }
        void delNode(Node *dNode)
        {
            Node *dprev = dNode->prev;
            Node *dnext = dNode->next;
            dprev->next = dnext;
            dnext->prev = dprev;
            --size;
        }
    };
    unordered_map<int, Node *> mp;
    unordered_map<int, List *> freq;
    int cacheSize, minFreq, currSize;

public:
    LFUCache(int capacity)
    {
        // Write your code here.
        cacheSize = capacity;
        minFreq = 0;
        currSize = 0;
    }
    void updateFreq(Node *currNode)
    {
        mp.erase(currNode->key);
        freq[currNode->count]->delNode(currNode);
        if (currNode->count == minFreq && freq[currNode->count]->size == 0)
        {
            minFreq++;
        }

        List *nextFreq = new List();
        if (freq.find(currNode->count + 1) != freq.end())
        {
            nextFreq = freq[currNode->count + 1];
        }
        currNode->count++;
        nextFreq->addNode(currNode);
        freq[currNode->count] = nextFreq;
        mp[currNode->key] = currNode;
    }

    int get(int key)
    {
        // Write your code here.
        if (mp.find(key) != mp.end())
        {
            Node *temp = mp[key];
            int x = temp->val;
            updateFreq(temp);
            return x;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here.
        if (cacheSize == 0)
            return;

        if (mp.find(key) != mp.end())
        {
            Node *temp = mp[key];
            temp->val = value;
            updateFreq(temp);
        }
        else
        {
            if (currSize == cacheSize)
            {
                List *list = freq[minFreq];
                mp.erase(list->tail->prev->key);
                freq[minFreq]->delNode(list->tail->prev);
                --currSize;
            }
            ++currSize;
            minFreq = 1;
            List *flist = new List();
            if (freq.find(minFreq) != freq.end())
            {
                flist = freq[minFreq];
            }
            Node *node = new Node(key, value);
            flist->addNode(node);
            mp[key] = node;
            freq[minFreq] = flist;
        }
    }
};
