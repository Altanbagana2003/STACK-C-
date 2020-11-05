#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next;
};

void insertStart(Node* &head, int elem) {
	Node *p = new Node;
	p -> data = elem;
	p -> next = head;
	head = p;
}

void addNodeIntoEnd(Node* &start, int elem) {
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

void insert(Node* &curr, int elem) {
	if (curr == NULL) {
		insertStart(curr, elem);
	} else {
		Node *p = new Node;
		p -> data = elem;
		p -> next = curr -> next;
		curr -> next = p;
	}
}

void remove(Node* &head, Node *curr) {
	if (curr == head) {
		head = head -> next;
	} else {
		Node *p = head;
		while (p -> next != curr) {
			p = p -> next;
		}
		p -> next = curr -> next;
	}
	delete curr;
}

Node* find(Node *head, int elem) {
	Node *curr = head;
	while (curr != NULL && curr -> data != elem) {
		curr = curr -> next;
	}
	return curr;
}

void print(Node *head) {
	Node *curr = head;
	while(curr != NULL) {
		cout << curr -> data << " ";
		curr = curr -> next;
	}
	cout << endl;
}

int findIndex (Node *head, int elem) {
	int i = 1;
	Node *curr = head;
	while (curr != NULL) {
		if (elem == curr -> data) {
			return i;
		} else {
			i++;
			curr = curr ->next;
		}
	}
	return -1;
}

Node *address (Node *head, int index) {
	index--;
	Node *curr = head;
	for (int i = 0; i < index; i++) {
		curr = curr -> next;
	}
	return curr;
}

int length(Node *head) {
	int i = 0;
	Node *curr  = head;
	while (curr != NULL) {
		curr = curr -> next;
		i++;
	}
	return i;
}

void removeFirstElement (Node* &head) {
	Node *curr = head;
	head = curr -> next;
	delete curr;
}

int main() {
	Node *head = NULL;
	insertStart(head, 3);
	insert(head, 2);
	insertStart(head, 1);
	print(head);
	insertStart(head, 4);
	print(head);
	Node *curr = find(head, 1);
	insert(curr, 5);
	print(head);
	curr = find(head, 3);
	remove(head, curr);
	print(head);
	int index = findIndex(head, 5);
	cout << index << endl;
	Node *addr = address (head, 1);
	cout << "Address: " << addr -> data << endl;
	int l = length(head);
	cout << "Length: " << l << endl;
	removeFirstElement(head);
	print(head);
	l = length(head);
	cout << l << endl;
	return 0;
}
