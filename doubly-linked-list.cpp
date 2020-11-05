#include <iostream>
#include <vector>
#include <cmath>

#define mp make_pair
#define ll long long

using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

void add_element_in_start(Node* &start, int element){
    Node *cur = new Node;
    cur -> data = element;
    cur -> next = start;
    cur -> prev = NULL;
    if(start != NULL)
        start -> prev = cur;
    start = cur;
}
void add_element_in_end(Node* &start, int element){
    Node *node = new Node;
    node -> data = element;
    node -> next = NULL;
    if(start == NULL){
        node -> prev = NULL;
        start = node;
        return;
    } 
    Node *cur = start;
    while(cur -> next != NULL)
        cur = cur ->next;
    cur -> next = node;
    node -> prev = cur;
} 
void delete_node(Node* &start, Node* cur){
    if(start == cur){
        start = start -> next;
        start -> prev = NULL;
        delete cur;
    } else {
        if(cur -> next == NULL){
            cur -> prev -> next = NULL;
            delete cur;
            return;
        }
        cur -> next -> prev = cur -> prev;
        cur -> prev -> next = cur -> next;
        delete cur;
    }
}

Node* find_node(Node* &start, int ele){
    Node* node = start;
    while(node -> data != ele && node -> next != NULL){
        node = node -> next;
    }
    return node;
}
void print(Node *node){
    Node* last = node;
    while (node != NULL) {  
        cout << node -> data <<  ' ';
        last = node;
        node = node->next;  
    }  
    cout << endl;
    while(last != NULL){
        cout << last -> data << ' ';
        last = last -> prev;
    }
    cout << endl;

}
int main(){
    Node* start = NULL;
    add_element_in_start(start, 1);
    add_element_in_end(start, 10);
    add_element_in_end(start, 100);
    add_element_in_start(start, 123);
    Node* cur = find_node(start, 100);
    delete_node(start, find_node(start, 1));
    // delete_node(start, cur);
    print(start);
    return 0;
}