//
//  main.cpp
//  HR_ds_stacks_maximum-element
//
//  Created by Jose Mari Syjuco on 16/2/21.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
};

class DLL {
public:
    DLL();
    ~DLL();
    bool empty() const;
    Node* front() const;
    Node* back() const;
    void add(int e, Node* v);
    void addSort(int e);
    void remove(Node* v);
    void removeVal(int e);
    void removeBack();
private:
    Node* head;
    Node* tail;
};

DLL::DLL() {
    head = new Node;
    tail = new Node;
    head->val = -1;
    tail->val = -1;
    head->next = tail;
    tail->prev = head;
}
DLL::~DLL() { while (!empty()) removeBack(); }
bool DLL::empty() const { return head->next == tail; }
Node* DLL::front() const { return empty() ? NULL : head->next; }
Node* DLL::back() const { return empty() ? NULL : tail->prev; }
void DLL::add(int e, Node* v) {
    Node* u = new Node;
    u->val = e;
    
    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}
void DLL::addSort(int e) {
    Node* node = front();
    if (node != NULL) {
        while (node->val != -1) {
            if (e > node->val) {
                add(e, node);
                return;
            }
            node = node->next;
        }
    }
    add(e, tail);
}
void DLL::remove(Node* v) {
    if (!empty()) {
        Node* u = v->prev;
        Node* w = v->next;
        u->next = w;
        w->prev = u;
        delete v;
    }
};
void DLL::removeVal(int e) {
    if (empty()) return;
    
    Node* node = front();
    while (node->val != -1) {
        if (e == node->val) {
            remove(node);
            return;
        }
        node = node->next;
    }
}
void DLL::removeBack() { if (!empty()) remove(tail->prev); };

class Stack {
    enum { DEF_CAP = 100005 };
public:
    Stack(int cap = DEF_CAP);
    ~Stack();
    int size() const;
    bool empty() const;
    int top() const;
    void push(int e);
    int pop();
private:
    int* S;
    int t;
    int capacity;
};  

Stack::Stack(int cap) : S(new int[cap]), t(-1), capacity(cap) { };
Stack::~Stack() { while (!empty()) pop(); }
int Stack::size() const { return t + 1; }
bool Stack::empty() const { return size() == 0; }
int Stack::top() const { return empty() ? -1 : S[t]; }
void Stack::push(int e) { if (size() != capacity) S[++t] = e; }
int Stack::pop() {
    if (!empty()) return S[t--];
    return -1;
}

vector<int> getMax(vector<string> operations) {
    vector<int> ans;
    
    int N = (int)operations.size();
    Stack* st = new Stack(N);
    DLL* dList = new DLL();
    
    vector<string>::iterator i = operations.begin();
    while(i != operations.end()) {
        const char type = i[0][0];
        if (type == '1') {
            int pos = (int) i->find(" ");
            string str = i->substr(pos + 1).c_str();
            int val = stoi(str);
            st->push(val);
            dList->addSort(val);
        } else if (type == '2') {
            int popped = st->pop();
//            printf("Popped: %d\n", popped);
            dList->removeVal(popped);
        } else {
            int max = dList->front()->val;
//            printf("MAX: %d\n", max);
            ans.push_back(max);
        }
        ++i;
    }
    
//    Node* node = dList->front();
//    while (node->val != -1) {
//        printf("%d ", node->val);
//        node = node->next;
//    }
//    printf("\n");
    return ans;
}


int main() {
    vector<string> ops = {"1 97", "2", "1 20", "2", "1 26", "1 20", "2", "3", "1 91", "3"};
    vector<int> res = getMax(ops);
    for (size_t i = 0; i < res.size(); i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}

/*
 10
 1 97
 2
 1 20
 2
 1 26
 1 20
 2
 3
 1 91
 3
 */
