//
//  main.cpp
//  HR_ds_stacks_maximum-element
//
//  Created by Jose Mari Syjuco on 16/2/21.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Node {
    int val;
};

class Stack {
    enum { DEF_CAP = 100005 };
public:
    Stack(int cap = DEF_CAP);
    ~Stack();
    int size() const;
    bool empty() const;
    Node* top() const;
    void push(int e);
    void pop();
private:
    Node** S;
    int t;
    int capacity;
};

Stack::Stack(int cap) : S(new Node*[cap]), t(-1), capacity(cap) { };
Stack::~Stack() { while (!empty()) pop(); }
int Stack::size() const { return t + 1; }
bool Stack::empty() const { return size() == 0; }
Node* Stack::top() const { return empty() ? NULL : S[t]; }
void Stack::push(int e) {
    if (size() != capacity) {
        Node* v = new Node;
        v->val = e;
        S[++t] = v;
    }
}
void Stack::pop() {
    if (!empty()) {
        delete S[t];
        --t;
    }
}


int main() {
    int N;
    int type;
    int val;
    int max = 0;
    
    Stack* st = new Stack();
    
    scanf("%d", &N);
    while (N > 0) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &val);
            printf("Add: %d\n", val);
            if (val > max) max = val;
            st->push(val);
        } else if (type == 2) {
            printf("Delete\n");
            st->pop();
        } else {
            printf("Print\n");
            printf("%d\n", max);
        }
        --N;
    }
    return 0;
}
