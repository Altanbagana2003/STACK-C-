#include <iostream>

using namespace std;

template<class T>
struct stack {
    struct node {
        T data;
        node *next;
    };

    node *head;
    int len;

    stack() {
        head = NULL;
        len = 0;
    }

    void push(T data) {
        node *p = new node;
        p -> data = data;
        p -> next = head;
        head = p;
        len++;
    }

    void pop() {
        node *p = head;
        head = head -> next;
        delete p;
        len--;
    }

    int size() {
        return len;
    }

    bool empty() {
        return len == 0;
    }

    T top() {
        return head -> data;
    }
};

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    cout << s.top() << "\n";
    s.pop();
    cout << s.top() << "\n";
    s.pop();
    return 0;
}