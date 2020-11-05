#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void addNodeIntoStart (Node* &start, int elem) {
    Node *current = new Node;
    current -> data = elem;
    current -> next = start;
    start = current;
}

void addNodeIntoEnd (Node* &start, int elem) {
    Node *current = start;
    if (start == NULL) {
        start = new Node;
        start -> data = elem;
        start -> next = NULL;
    } else {
        Node *current = start;
        while (current -> next != NULL) {
            current = current -> next;
        }
        current -> next = new Node;
        current = current -> next;
        current -> next = NULL;
        current -> data = elem;
    }
}

void addNode (Node* &current, int elem) {
    Node *node = new Node;
    node -> data = elem;
    node -> next = current -> next;
    current -> next = node;
}

void deleteNode (Node* &start, Node *current) {
    if (current == start) {
        start = start -> next;
        delete current;
    } else {
        Node *node = start;
        while (node -> next != current) {
            node = node -> next;
        }
        node -> next = current -> next;;
        delete current;
    }
}

Node* findNode (Node *node, int elem) {
    while (node != NULL && node -> data != elem) {
        node = node -> next;
    }
    return node;
}

void print (Node *node) {
    while (node != NULL) {
        cout << node -> data << " ";
        node = node -> next;
    }
    cout << endl;
}

int main () {
    Node *start = NULL;
    addNodeIntoStart(start, 1);
    addNodeIntoStart(start, 10);
    addNodeIntoEnd(start, 2);
    addNodeIntoEnd(start, 3);
    addNodeIntoEnd(start, 4);
    addNode(start, 5);
    addNode(start, 6);
    print(start);
    Node *current = findNode(start, 2);
    deleteNode(start, current);
    print(start);
    return 0;
}