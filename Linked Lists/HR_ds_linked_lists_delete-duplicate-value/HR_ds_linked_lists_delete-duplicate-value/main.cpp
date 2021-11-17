//
//  main.cpp
//  HR_ds_linked_lists_delete-duplicate-value
//
//  Created by Jose Mari Syjuco on 23/2/21.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

class Node {
public:
    Node(int val);
    int data;
    Node* next;
};
Node::Node(int val) : data(val) { }

Node* removeDuplicates(Node* head) {
    Node* front = new Node(0);
    Node* cursor = NULL;
    int prev = -1;
    
    while (head != NULL) {
        int val = head->data;
        if (val != prev) {
            Node* v = new Node(val);
            if (cursor == NULL) {
                v->next = NULL;
                front->next = v;
                cursor = v;
            } else {
                v->next = cursor->next;
                cursor->next = v;
                cursor = v;
            }
            prev = val;
        }
        head = head->next;
    }
    return front->next;
}

int main() {
    return 0;
}

// 1
// 5
// 1
// 2
// 2
// 3
// 4

// 1 2 3 4
