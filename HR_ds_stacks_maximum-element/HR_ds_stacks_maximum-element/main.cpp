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
    
    vector<string>::iterator i = operations.begin();
    while(i != operations.end()) {
        const char type = i[0][0];
        if (type == '1') {
            int pos = (int) i->find(" ");
            string str = i->substr(pos + 1).c_str();
            int val = stoi(str);
            
            if (st->empty()) {
                st->push(val);
            } else {
                int max_so_far = st->top();
                
                if (val > max_so_far) st->push(val);
                else st->push(max_so_far);
            }
        } else if (type == '2') {
            int popped = st->pop();
            printf("Popped: %d\n", popped);
        } else {
            int max = st->top();
            printf("MAX: %d\n", max);
            ans.push_back(max);
        }
        ++i;
    }
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
