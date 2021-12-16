//
//  main.cpp
//  Topological Sort
//
//  Created by Jose Mari Syjuco on 16/12/21.
//

#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps) {
    unordered_map<int, vector<int>> adjList;
    unordered_map<int, int> depCount;
    unordered_map<int, bool> visited;
    
    // Create adjacency list
    // Count number of deps per job
    for (auto job : jobs) {
        adjList.insert({ job, vector<int>{} });
        depCount.insert({ job, 0 });
        visited.insert({ job, false });
    }
    for (auto dep : deps) {
        int task1 = dep[0];
        int task2 = dep[1];
        adjList[task1].push_back(task2);
        depCount[task2]++;
    }
    
    // Create queue, add jobs that dont have dependencies first
    queue<int> mustFinishFirst;
    for (auto job : depCount) {
        if (job.second == 0) {
            mustFinishFirst.push(job.first);
            visited[job.first] = true;
        }
    }
    
    vector<int> ans;
    while (!mustFinishFirst.empty()) {
        // Get first completed job
        int completedTask = mustFinishFirst.front();
        mustFinishFirst.pop();
        ans.push_back(completedTask);
        
        // Visit next tasks after this current job
        for (int i = 0; i < adjList[completedTask].size(); ++i) {
            int nextTask = adjList[completedTask][i];
            // Reduce the number of dependencies for next task since we completed pre req
            depCount[nextTask]--;
            // If next task does not have any deps, we can add to queue
            if (depCount[nextTask] == 0 && !visited[nextTask]) {
                mustFinishFirst.push(nextTask);
                visited[nextTask] = true;
            }
        }
    }
    // If the number of jobs != completed jobs then there's a cycle
    return jobs.size() == ans.size() ? ans : vector<int>{};
}

int main(int argc, const char * argv[]) {
    vector<int> jobs = {1, 2, 3, 4};
    vector<vector<int>> deps = {{1, 2}, {1, 3}, {3, 2}, {4, 2}, {4, 3}};
    vector<int> order = topologicalSort(jobs, deps);
    
    for (auto o : order) cout << o << " ";
    cout << "\nFIN\n";
    return 0;
}
