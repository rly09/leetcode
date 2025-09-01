#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string url;
    Node* next;
    Node* prev;

    Node(string u) : url(u), next(nullptr), prev(nullptr) {}
};

class BrowserHistory {
private:
    Node* current;  // pointer to the current page
public:
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        current->next = newNode;   // clear forward history
        newNode->prev = current;
        current = newNode;         // move to new page
    }
    
    string back(int steps) {
        while (steps > 0 && current->prev) {
            current = current->prev;
            steps--;
        }
        return current->url;
    }
    
    string forward(int steps) {
        while (steps > 0 && current->next) {
            current = current->next;
            steps--;
        }
        return current->url;
    }
};
