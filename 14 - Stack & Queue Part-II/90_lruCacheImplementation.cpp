#include <bits/stdc++.h>

class LRUCache
{
    class Node
    {
    public:
        int key, val;
        Node *prev, *next;
        Node(int k, int d)
        {
            key = k;
            val = d;
            next = prev = NULL;
        }
    };
    int totalSize;
    unordered_map<int, Node *> mp;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    void addNode(Node *nNode)
    {
        Node *temp = head->next;
        nNode->next = temp;
        nNode->prev = head;
        head->next = nNode;
        temp->prev = nNode;
    }
    void delNode(Node *dNode)
    {
        Node *dprev = dNode->prev;
        Node *dnext = dNode->next;
        dprev->next = dnext;
        dnext->prev = dprev;
    }

public:
    LRUCache(int capacity)
    {
        // Write your code here
        totalSize = capacity;
        head->next = tail;
        tail->prev = head;
    }
    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            Node *temp = mp[key];
            int val = temp->val;
            delNode(temp);
            addNode(temp);
            mp[key] = head->next;
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here
        if (mp.find(key) != mp.end())
        {
            Node *temp = mp[key];
            mp.erase(key);
            delNode(temp);
        }
        else if (mp.size() == totalSize)
        {
            mp.erase(tail->prev->key);
            delNode(tail->prev);
        }
        Node *x = new Node(key, value);
        addNode(x);
        mp[key] = head->next;
    }
};
