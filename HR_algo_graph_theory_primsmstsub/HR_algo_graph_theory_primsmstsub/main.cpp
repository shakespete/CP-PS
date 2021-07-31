#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

struct Node {
    int weight;
    int key;
};
class Heap {
    enum { DEF_CAP = 100 };
public:
    Heap(int cap = DEF_CAP);
    ~Heap();
    int size() const;
    bool empty() const;
    Node* root() const;
    void push(const int k, const int w);
    Node* pop();
private:
    Node** H;
    int n;
    int capacity;
};

Heap::Heap(int cap) : H(new Node*[cap]), n(0), capacity(cap) { }
Heap::~Heap() { while (!empty()) pop(); }
int Heap::size() const { return n; }
bool Heap::empty() const { return n == 0; }
Node* Heap::root() const { return empty() ? NULL : H[1]; }
void Heap::push(const int k, const int w) {
    if (size() != capacity) {
        Node* v = new Node();
        v->key = k;
        v->weight = w;
        
        n++;
        H[n] = v;

        int current = n;
        while (current > 1 && H[current]->weight < H[current / 2]->weight) {
            int parent = current / 2;

            Node* temp = H[parent];
            H[parent] = H[current];
            H[current] = temp;
            current = parent;
        }
    }
}
Node* Heap::pop() {
    if (!empty()) {
        Node* nextNode = new Node();
        nextNode->key = H[1]->key;
        nextNode->weight = H[1]->weight;
        
        delete H[1];
        H[1] = H[n];
        --n;

        int current = 1;
        while (current * 2 <= n) {
            int child;
            int left = current * 2;
            int right = current * 2 + 1;

            if (left == n) child = left;
            else child = H[left]->weight < H[right]->weight ? left : right;

            if (H[current]->weight < H[child]->weight) break;

            Node* temp = H[child];
            H[child] = H[current];
            H[current] = temp;
            current = child;
        }
        return nextNode;
    }
    return NULL;
}

int prims(int n, vector<vector<int>> edges, int start) {
    printf("%d %d\n", n, start);
    int ans = 0;
    int N = n + 1;
    int* visited = new int[N]{0};
    
    int** adjList = new int*[N];
    for (int i = 0; i < N; ++i) {
        visited[i] = -1;
        adjList[i] = new int[N]{0};
    }
    
    for (int i = 0; i < edges.size(); ++i) {
        adjList[edges[i][0]][edges[i][1]] = edges[i][2];
        adjList[edges[i][1]][edges[i][0]] = edges[i][2];
    }
    
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < N; ++j) {
//            printf("%d ", adjList[i][j]);
//        }
//        printf("\n");
//    }
    
    Heap* h = new Heap(N);
    h->push(start, 0);
    
    while (!h->empty()) {
        Node* node = h->pop();
        int currKey = node->key;
        int currWeight = node->weight;
        
        if (visited[currKey] == -1) {
            visited[currKey] = currWeight;
            printf("Visited %d (%d)\n", currKey, currWeight);
             ans += currWeight;
        };
        
//        printf("From: %d\n", currKey);
        
        for (int i = 1; i < N; ++i) {
//            printf(" %d %d\n", i, adjList[currKey][i]);
            if (visited[i] == -1 && adjList[currKey][i] != 0) {
//                printf("%d -> %d => %d\n", currKey, i, adjList[currKey][i]);
                h->push(i, adjList[currKey][i]);
            }
        }
    }
    
    return ans;
}

int main() {
//    Heap* h = new Heap();
//    h->push(1, 2);
//    h->push(3, 6);
//    printf("%d\n", h->pop());
//    h->push(2, 3);
//    h->push(4, 5);
//    h->push(3, 8);
//    printf("%d\n", h->pop());
//    h->push(4, 7);
//    printf("%d\n", h->pop());
//    h->push(3, 9);
//    printf("%d\n", h->pop());
    
//    h->push(2, 3);
//    h->push(3, 4);
//    printf("%d\n", h->pop());
//    h->push(5, 2);
//    h->push(4, 6);
//    h->push(3, 5);
//    printf("%d\n", h->pop());
//    printf("%d\n", h->pop());
//    printf("%d\n", h->pop());
//    printf("%d\n", h->pop());
    
//    vector<vector<int>> edges_1(6);
//    edges_1[0] = { 1, 2, 3 };
//    edges_1[1] = { 1, 3, 4 };
//    edges_1[2] = { 4, 2, 6 };
//    edges_1[3] = { 5, 2, 2 };
//    edges_1[4] = { 2, 3, 5 };
//    edges_1[5] = { 3, 5, 7 };
//    int ans = prims(5, edges_1, 1);
    
    vector<vector<int>> edges_1(7);
    edges_1[0] = { 1, 2, 20 };
    edges_1[1] = { 1, 3, 50 };
    edges_1[2] = { 1, 4, 70 };
    edges_1[3] = { 1, 5, 90 };
    edges_1[4] = { 2, 3, 30 };
    edges_1[5] = { 3, 4, 40 };
    edges_1[6] = { 4, 5, 60 };
    int ans = prims(5, edges_1, 2);
    
    printf("FIN: %d\n", ans);

    return 0;
}
