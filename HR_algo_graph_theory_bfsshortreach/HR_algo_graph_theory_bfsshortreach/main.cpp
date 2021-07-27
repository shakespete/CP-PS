//
//  main.cpp
//  HR_algo_graph_theory_bfsshortreach
//
//  Created by Jose Mari Syjuco on 22/7/21.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

struct Node {
    int key;
    int value;
};

// Simple Queue
class Queue {
    enum { DEF_CAP = 1005 };
public:
    Queue(int cap = DEF_CAP);
    bool empty();
    void enq(int e, int v);
    Node* deq();
private:
    Node** q;
    int capacity;
    int front;
    int rear;
};

Queue::Queue(int cap) : front(0), rear(0), capacity(cap), q(new Node*[cap]) { };
bool Queue::empty() { return front == rear; }
void Queue::enq(int e, int v) {
    Node* node = new Node();
    node->key = e;
    node->value = v;
    q[rear++] = node;
}
Node* Queue::deq() {
    if (!empty()) return q[front++];
    return NULL;
}

// Graph (BFS)
class Graph {
public:
    Graph(int nodes);
    void addEdge(int v, int w);
    void BFS(int start);
    int* visited;
private:
    int n;          // Number of vertices
    int** adjList;  // Adjacency list
};

Graph::Graph(int nodes) {
    n = nodes;
    adjList = new int*[n];
    visited = new int[n]{0};
    
    for (int i = 1; i < n; ++i)
        adjList[i] = new int[n]{0};
}
void Graph::addEdge(int v, int w) {
    adjList[v][w] = 1;
    adjList[w][v] = 1;
}
void Graph::BFS(int start) {
    int m = (n * (n - 1)) / 2;
    Queue* q = new Queue(m);
    q->enq(start, 0);
    
    while (!q->empty()) {
        Node* node = q->deq();
        int key = node->key;
        int acc = node->value;
        
        // printf("%d (%d)\n", key, acc);
        for (int i = 1; i < n; ++i) {
            if (adjList[key][i] == 1 && start != i) {
                if (visited[i] == 0 || acc < visited[i]) {
                    int sum = acc + 6;
                    visited[i] = sum;
                    q->enq(i, sum);
                }
            }
        }
    }
    
//    for (int i = 1; i < n; ++i) printf("%d ", visited[i]);
//    printf("\n");
}

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<int> ans;
    
    int nodes = n + 1;
    Graph* g = new Graph(nodes);
    for (auto& edge: edges) g->addEdge(edge[0], edge[1]);
    
    g->BFS(s);
    for (int i = 1; i < nodes; ++i) {
        if (i != s) {
            int val = g->visited[i];
            if (val == 0) ans.push_back(-1);
            else ans.push_back(val);
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
//    vector<vector<int>> edges_1(15);
//    edges_1[0] = { 1, 2 };
//    edges_1[1] = { 1, 3 };
//    edges_1[2] = { 3, 4 };
//    edges_1[3] = { 3, 9 };
//    edges_1[4] = { 4, 6 };
//    edges_1[5] = { 4, 7 };
//    edges_1[6] = { 4, 8 };
//    edges_1[7] = { 7, 10 };
//    edges_1[8] = { 8, 11 };
//    edges_1[9] = { 2, 12 };
//    edges_1[10] = { 12, 13 };
//    edges_1[11] = { 13, 14 };
//    edges_1[12] = { 13, 15 };
//    edges_1[13] = { 13, 17 };
//    edges_1[14] = { 15, 16 };
//
//    vector<int> ans_1 = bfs(17, 9, edges_1, 1);
//    for (int i = 0; i < ans_1.size(); ++i) printf("%d ", ans_1[i]);
//    printf("\n");
    
    
    vector<vector<int>> edges_1(3);
    edges_1[0] = { 1, 2 };
    edges_1[1] = { 1, 3 };
    edges_1[2] = { 3, 4 };
    vector<int> ans_1 = bfs(5, 3, edges_1, 1);
    for (int i = 0; i < ans_1.size(); ++i) printf("%d ", ans_1[i]);
    printf("\n");
    
    vector<vector<int>> edges_2(2);
    edges_2[0] = { 1, 2 };
    edges_2[1] = { 1, 3 };
    vector<int> ans_2 = bfs(4, 2, edges_2, 1);
    for (int i = 0; i < ans_2.size(); ++i) printf("%d ", ans_2[i]);
    printf("\n");

    vector<vector<int>> edges_3(1);
    edges_3[0] = { 2, 3 };
    vector<int> ans_3 = bfs(3, 1, edges_3, 2);
    for (int i = 0; i < ans_3.size(); ++i) printf("%d ", ans_3[i]);
    printf("\n");
    
    return 0;
}
