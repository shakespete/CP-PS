//
//  main.cpp
//  HR_ds_arrays_sparse-arrays
//
//  Created by Jose Mari Syjuco on 8/2/21.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

bool is_equal(const char* a, const char* b) {
    while (*a == *b) {
        if (*a == '\0') return true;
        ++a;
        ++b;
    }
    return false;
}

struct Node {
    const char* val;
    int count;
};

class SArray {
    enum { DEF_CAP = 1005 };
public:
    SArray(int cap = DEF_CAP);
    int size() const;
    bool empty() const;
    Node* find(const char* e);
    int count(const char* e);
    void push(const char* e);
private:
    Node** A;
    int n;
    int capacity;
};

SArray::SArray(int cap) : A(new Node*[cap]), capacity(cap), n(0) { }
int SArray::size() const { return n; }
bool SArray::empty() const { return n == 0; }
Node* SArray::find(const char* e) {
    if (!empty()) {
        for (int i = 0; i < n; ++i) {
            if (is_equal(e, A[i]->val)) return A[i];
        }
    }
    return NULL;
}
int SArray::count(const char* e) {
    Node* node = find(e);
    if (node != NULL) { return node->count; }
    return 0;
}
void SArray::push(const char* e) {
    Node* node = find(e);
    if (node != NULL) {
        node->count = node->count + 1;
    } else {
        Node* v = new Node;
        v->val = e;
        v->count = 1;
        A[n++] = v;
    }
}

int main(int argc, const char * argv[]) {
    int N = 10;
    SArray* sArr = new SArray(N);
    sArr->push("def");
    sArr->push("de");
    sArr->push("fgh");
    
    printf("%d ", sArr->count("de"));
    printf("%d ", sArr->count("lmn"));
    printf("%d ", sArr->count("fgh"));
    printf("\n");
    return 0;
}
