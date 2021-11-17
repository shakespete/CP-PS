//
//  main.cpp
//  Cycle in Graph
//
//  Created by Jose Mari Syjuco on 17/11/21.
//

#include <stdio.h>
#include <vector>

using namespace std;


bool dfs(int currIdx, vector<vector<int>> &edges, vector<int> &vis) {
    if (vis[currIdx] == 1) return true;
    vis[currIdx] = 1; // Mark visited
    
    // Go through this node's edges
    for (int i = 0; i < edges[currIdx].size(); ++i) {
        bool cycle = dfs(edges[currIdx][i], edges, vis);
        if (cycle) return true;
    }
    
    vis[currIdx] = 0; // Done: reset to 0
    return false;
}

bool hasCycle(vector<vector<int>> edges) {
    int N = (int)edges.size();
    vector<int> vis(N, 0);
    
    // Start with each vertex
    for (int i = 0; i < N; ++i) {
        bool cycle = dfs(i, edges, vis);
        if (cycle) return true;
    }
    return false;
}

int main() {
    vector<vector<int>> edges = {
        {1, 3},
        {2, 3, 4},
        {0},
        {},
        {2, 5},
        {}
    };
    bool cycle = hasCycle(edges);
    cycle ? printf("true") : printf("false");
    printf("\nFIN\n");
    return 0;
}
