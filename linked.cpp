#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

void insertStart(Node* &head, int elem) {
    if (head == NULL) {
        head = new Node;
        head -> next = NULL;
        head -> prev = NULL;
        head -> data = elem;
    } else {
        Node *p = new Node;
        p -> data = elem;
        p -> next = head;
        head -> prev = p;
        p -> prev = NULL;
        head = p;
    }
}

Node *findIndex(Node *head, int elem) {
    Node *curr = head;
    while (curr != elem) {
        curr = curr -> next;
        i++;
    }
}

void print(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        cout << curr -> data << " ";
        curr = curr -> next;
    }
    cout << endl;
}

int main () {
    Node *head = NULL;
    insertStart(head, 5);
    insertStart(head, 2);
    insertStart(head, 1);
    print(head);
    findIndex(head, 2);

    return 0;
}