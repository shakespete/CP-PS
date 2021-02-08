#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
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

// Complete the matchingStrings function below.
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    SArray* sArr = new SArray(strings.size());
    
    for (auto i = 0U; i < strings.size(); ++i) {
        // printf("%s ", strings[i].c_str());
        sArr->push(strings[i].c_str());
    }
    // printf("\n");
    
    vector<int> ans;
    for (auto i = 0U; i < queries.size(); ++i) {
        // printf("%s ", queries[i].c_str());
        int count = sArr->count(queries[i].c_str());
        ans.push_back(count);
        // printf("%d\n", count);
    }
    return ans;
}

int main()
{
//    ofstream fout(getenv("OUTPUT_PATH"));

    int strings_count;
    cin >> strings_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> strings(strings_count);

    for (int i = 0; i < strings_count; i++) {
        string strings_item;
        getline(cin, strings_item);

        strings[i] = strings_item;
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item;
        getline(cin, queries_item);

        queries[i] = queries_item;
    }

    vector<int> res = matchingStrings(strings, queries);

    for (auto i = 0U; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
