#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void push (Node* &head, int elem) {
    Node *p = new Node;
    p -> data = elem;
    p -> next = head;
    head = p;
}

void print(Node *head) {
	Node *curr = head;
	while(curr != NULL) {
		cout << curr -> data << " ";
		curr = curr -> next;
	}
	cout << endl;
}

void pop (Node* &head) {
    Node *curr = head;
    head = curr -> next;
    delete curr;
}

int top (Node *head) {
    Node *curr = head;
    return curr -> data;
}

bool is_emptyi (Node *head) { 
    if (head == NULL) {
        return true;
    } else {
        return false;
    }
}

int size (Node *head) {
    Node *curr = head;
    int count = 1;
    while (curr -> next != NULL) {
        curr = curr -> next;
        count++;
    }
    return count;
}

int main () {
    Node *head = NULL;
    push(head, 10);
    push(head, 20);
    push(head, 30);
    print(head);
    pop(head);
    print(head);
    int elem = top(head);
    cout << "top element: " << elem << endl;
    bool check = is_emptyi(head);
    if (check == true) {
        cout << "EMPTY" << endl;
    } else {
        cout << "NOT EMPTY" << endl;
    }
    pop(head);
    pop(head);
    print(head);
    check = is_emptyi(head);
    if (check == true) {
        cout << "EMPTY" << endl;
    } else {
        cout << "NOT EMPTY" << endl;
    }
    push(head, 100);
    push(head, 200);
    push(head, 300);
    print(head);
    int counter = size(head);
    cout << "Size of stack: " << counter << endl;
    return 0;
}
