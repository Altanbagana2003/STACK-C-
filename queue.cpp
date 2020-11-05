#include <iostream>
using namespace std;
struct node {
	int data;
	node *next;
};
void addElementToEnd (node* &head, node* &tail, int elem) {
	node *p = new node;
    p -> data = elem;
    if (tail == NULL) {
        tail = p;
        head = p;
    } else {
        tail -> next = p;
        tail = p;
    }
}
void print(node *head) {
	node *curr = head;
	while (curr != NULL) {
		cout << curr -> data << " ";
		curr = curr -> next;
	} cout << endl;
}
int main () {
	node *head = NULL;
    node *tail = NULL;
	addElementToEnd(head, tail, 10);
	addElementToEnd(head, tail, 20);
	addElementToEnd(head, tail, 30);
	print(head);
	return 0;
}