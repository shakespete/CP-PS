//
//  main.cpp
//  HR_algo_strings_weighted-uniform-string
//
//  Created by Jose Mari Syjuco on 3/9/21.
//

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* next;
};
class LL {
public:
    LL();
    bool empty() const;
    Node* front() const;
    void add(int e);
private:
    Node* head;
};
LL::LL() : head(NULL) {};
bool LL::empty() const { return head == NULL; }
Node* LL::front() const { return empty() ? NULL : head; }
void LL::add(int e) {
    Node* v = new Node;
    v->val = e;
    v->next = head;
    head = v;
}

class HashMap {
    enum { DEF_CAP = 1000 };
public:
    HashMap(int cap = DEF_CAP);
    int hash(int e);
    void insert(int e);
    string retrieve(int e);
private:
    LL* HM;
    int capacity;
};

HashMap::HashMap(int cap) : HM(new LL[cap]), capacity(cap) { }
int HashMap::hash(int e) {
    int hash = e * 31;
    int hashVal = hash % capacity;
    return hashVal;
}
void HashMap::insert(int e) {
    int hashVal = hash(e);
    Node* v = new Node;
    v->val = e;
    HM[hashVal].add(e);
}
string HashMap::retrieve(int e) {
    int hashVal = hash(e);
    if (HM[hashVal].empty()) return "NO";
    
    Node* node = HM[hashVal].front();
    while (node) {
        if (node->val == e) return "YES";
        node = node->next;
    }
    return "NO";
}

int getLetterVal(char e) {
    return e - 'a' + 1;
}


vector<string> weightedUniformStrings(string s, vector<int> queries) {
    vector<string> res;
    
    HashMap* hm = new HashMap();
    
    int acc = 0;
    for (int i = 0; i < s.size(); ++i) {
        int curr = getLetterVal(s[i]);
        if (i == 0) {
            printf("%d\n", curr);
            hm->insert(curr);
        } else if (getLetterVal(s[i - 1]) == curr) {
            acc += curr;
            printf("%d\n", acc);
            hm->insert(acc);
        } else {
            acc = curr;
            printf("%d\n", curr);
            hm->insert(curr);
        }
    }
    
    for (int i = 0; i < queries.size(); ++i) {
        string ans = hm->retrieve(queries[i]);
        res.push_back(ans);
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
    string s = "abccddde";
    vector<int> queries = {1, 7, 5, 4, 15};
        
    vector<string> ans = weightedUniformStrings(s, queries);
    
    return 0;
}
