//
//  main.cpp
//  All Paths
//
//  Created by Jose Mari Syjuco on 28/11/21.
//

#include <iostream>
#include <vector>

using namespace std;

void dfs(int curr, int target,
         vector<vector<int>>& graph, vector<bool>& visited,
         vector<int>& path, vector<vector<int>>& ans) {
    
    if (visited[curr]) return;
    path.push_back(curr);
    
    cout << "Current:\n";
    for (auto x : path) cout << x << " ";
    cout << "\n";
    
    if (curr == target) {
        ans.push_back(path);
        path.pop_back();
        
        cout << "-------- END --------\n";
        cout << "Backtrack on end:\n";
        for (auto x : path) cout << x << " ";
        cout << "\n";
        
        return;
    }
    
    visited[curr] = true;
    
    for (int vertex : graph[curr]) {
        cout << "DFS:\n";
        dfs(vertex, target, graph, visited, path, ans);
    }
    
    path.pop_back();
    visited[curr] = false;
    
    cout << "Backtrack after neighbor loop of: " << curr << "\n";
    for (auto x : path) cout << x << " ";
    cout << "\n";
}

vector<vector<int>> allPaths(vector<vector<int>>& graph) {
    vector<vector<int>> ans;
    int N = (int)graph.size();
    vector<bool> visited(N, false);
    
    vector<int> path;
    dfs(0, N - 1, graph, visited, path, ans);
    
    return ans;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> n1 = {{1, 2}, {3}, {3}, {}};
//    vector<vector<int>> n2 = {{4,3,1}, {3,2,4}, {3}, {4}, {}};
    vector<vector<int>> ans = allPaths(n1);
    
    for (auto i : ans) {
        for (auto x : i) {
            cout << x << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
