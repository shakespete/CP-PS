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

// Simple Queue
class Queue {
    enum { DEF_CAP = 1000 };
public:
    Queue(int cap = DEF_CAP);
    bool empty();
    void enq(int e);
    int deq();
private:
    int* q;
    int capacity;
    int front;
    int rear;
};

Queue::Queue(int cap) : front(0), rear(0), capacity(cap), q(new int[cap]) {};
bool Queue::empty() { return front == rear; }
void Queue::enq(int e) {
    if (rear == capacity) {
        int* temp = new int[capacity * 2];
        for (int i = 0; i < capacity; ++i) temp[i] = q[i];
        q = temp;
        capacity *= 2;
    }
    q[rear++] = e;
}
int Queue::deq() {
    if (!empty()) return q[front++];
    return -1;
}

// Graph (BFS)
class Graph {
public:
    Graph(int e);
    void addEdge(int v, int w);
    void BFS(int s);
    int* valArray;
private:
    int V;          // Number of vertices
    int** adjList;  // Adjacency list
    int* visited;
};

Graph::Graph(int e) {
    V = e;
    adjList = new int*[e];
    visited = new int[e]{0};
    valArray = new int[e]{0};
    
    for (int i = 1; i < e; ++i)
        adjList[i] = new int[e]{0};
}
void Graph::addEdge(int v, int w) {
    adjList[v][w] = 1;
    adjList[w][v] = 1;
}
void Graph::BFS(int s) {
//    for (int i = 1; i < V; ++i) {
//        for (int j = 1; j < V; ++j) printf("%d ", adjList[i][j]);
//        printf("\n");
//    }
    
    Queue* q = new Queue();
    q->enq(s);
    
    int val = 0;
    while (!q->empty()) {
        int u = q->deq();
        visited[u] = 1;
        printf("%d ", u);
        for (int i = 1; i < V; ++i)
            if (adjList[u][i] == 1)
                if (visited[i] != 1) {
                    q->enq(i);
                }
    }
}

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<int> ans;
    
    int nodes = n + 1;
    Graph* g = new Graph(nodes); // 18
    for (auto& edge: edges) g->addEdge(edge[0], edge[1]);
    
    g->BFS(s);
    printf("\n");
    for (int i = 1; i < nodes; ++i) {
        if (i != s) ans.push_back(g->valArray[i]);
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> edges_1(15);
    edges_1[0] = { 1, 2 };
    edges_1[1] = { 1, 3 };
    edges_1[2] = { 3, 4 };
    edges_1[3] = { 3, 9 };
    edges_1[4] = { 4, 6 };
    edges_1[5] = { 4, 7 };
    edges_1[6] = { 4, 8 };
    edges_1[7] = { 7, 10 };
    edges_1[8] = { 8, 11 };
    edges_1[9] = { 2, 12 };
    edges_1[10] = { 12, 13 };
    edges_1[11] = { 13, 14 };
    edges_1[12] = { 13, 15 };
    edges_1[13] = { 13, 17 };
    edges_1[14] = { 15, 16 };
    
    vector<int> ans_1 = bfs(17, 9, edges_1, 1);
    for (int i = 0; i < ans_1.size(); ++i) printf("%d ", ans_1[i]);
    printf("\n");
    
    
//    vector<vector<int>> edges_1(3);
//    edges_1[0] = { 1, 2 };
//    edges_1[1] = { 1, 3 };
//    edges_1[2] = { 3, 4 };
//    vector<int> ans_1 = bfs(5, 3, edges_1, 1);
//    for (int i = 0; i < ans_1.size(); ++i) printf("%d ", ans_1[i]);
//    printf("\n");
    
//    vector<vector<int>> edges_2(2);
//    edges_2[0] = { 1, 2 };
//    edges_2[1] = { 1, 3 };
//    vector<int> ans_2 = bfs(4, 2, edges_2, 1);
//    for (int i = 0; i < ans_2.size(); ++i) printf("%d ", ans_2[i]);
//    printf("\n");
//
//    vector<vector<int>> edges_3(1);
//    edges_3[0] = { 2, 3 };
//    vector<int> ans_3 = bfs(3, 1, edges_3, 2);
//    for (int i = 0; i < ans_3.size(); ++i) printf("%d ", ans_3[i]);
//    printf("\n");
    
    return 0;
}
