#include <iostream>
using namespace std;

template<class T>
struct queue {
    struct node {
        T data;
        node *next;
    };

    node *head;
    node *tail;
    int len;

    queue() {
        head = NULL;
        tail = NULL;
        len = 0;
    }

    void push (T data) {
        node *p = new node;
        p -> data = data;
        if (tail == NULL) {
            tail = p;
            head = p;
        } else {
            tail -> next = p;
            tail = p;
        }
        len++;
    }

    void pop () {
        node *p = head;
        head = head -> next;
        delete p;
        len--;
    }

    int size () {
        return len;
    }

    T top() {
        return head -> data;
    }

    bool isEmpty () {
        if (len == 0) {
            return true;
        } else {
            return false;
        }
    }

};

int main () {
    queue<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.pop();
    s.pop();
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    return 0;
}