#ifndef REVERSE_LIST_H
#define REVERSE_LIST_H

struct Node {
    int data;
    Node* next_;
    Node(int val) : data(val), next_(nullptr) {}
};

Node* reverse_list(Node* head);
void print_list(Node* head);

#endif // REVERSE_LIST_H