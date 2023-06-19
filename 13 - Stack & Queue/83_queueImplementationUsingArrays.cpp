// #include <bits/stdc++.h> 

// class Queue {
//     vector<int> stack;
//     int currIndex;
//     int topIndex;
// public:
//     Queue() {
//         // Implement the Constructor
//         currIndex=topIndex=0;
//     }

//     /*----------------- Public Functions of Queue -----------------*/

//     bool isEmpty() {
//         // Implement the isEmpty() function
//         return (topIndex==currIndex);
//     }

//     void enqueue(int data) {
//         // Implement the enqueue() function
//         stack.push_back(data);
//         currIndex++;
//     }

//     int dequeue() {
//         // Implement the dequeue() function
//         if(topIndex==currIndex) return -1;
//         int val = stack[topIndex];
//         topIndex++;
//         return val;
//     }

//     int front() {
//         // Implement the front() function
//         if(topIndex==currIndex) return -1;
//         int val = stack[topIndex];
//         return val;
//     }
// };

#include <bits/stdc++.h> 

class Node{
    public:
    int val;
    Node* next;
    Node(int data){
        val = data;
        next = NULL;
    }
};

class Queue {
    Node* root;
    Node* curr;
public:
    Queue() {
        // Implement the Constructor
        root=curr=NULL;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return (root==NULL);
    }

    void enqueue(int data) {
        // Implement the enqueue() function

        Node* x = new Node(data);
        if(root==NULL){
            root=curr=x;
            return;
        }
        curr->next = x;
        curr = curr->next;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(root==NULL) return -1;
        Node *z = root;
        int deq = z->val;
        root= z->next;
        free(z);
        if(root==NULL)
            curr=NULL;

        return deq;
    }

    int front() {
        // Implement the front() function
        if(root==NULL) return -1;
        int top = root->val;
        return top;
    }
};