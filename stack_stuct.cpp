#include <>

struct node {
    int data;
    node *next;
};

struct stack {
    node *head;
    int len;
    stack() {
        head = NULL;
        len = 0;
    }

    void push (int elem) {
        node *p = new node;
        p -> data = elem;
        p -> next = head;
        head = p;
        len++;
    }

    int size() { return len; }
    bool is_empty() { return len == 0; }
    int top() { return head -> data; }
    void pop() { node *temp = head; head = head -> next; delete temp; }
};

int main() {
    stack st;
    st.push(10);
}