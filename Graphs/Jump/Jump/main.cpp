//
//  main.cpp
//  Jump
//
//  Created by Jose Mari Syjuco on 9/12/21.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Time: O(n) | Space: O(n)
bool canReach(vector<int>& arr, int start) {
    int N = (int)arr.size();
    queue<int> q;
    vector<bool> visited(N, false);
    q.push(start);
    
    while (!q.empty()) {
        int currIdx = q.front();
        visited[currIdx] = true;
        q.pop();
        
        int jump = arr[currIdx];
        if (jump == 0) return true;
        
        int advance = currIdx + jump;
        int retreat = currIdx - jump;
        
        if (advance < N && !visited[advance]) {
            q.push(advance);
        }
        if (retreat >= 0 && !visited[retreat]) {
            q.push(retreat);
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    vector<int> n1 = {4,2,3,0,3,1,2};
    int s1 = 5;
    cout << canReach(n1, s1) << "\n";
    
    vector<int> n2 = {3,0,2,1,2};
    int s2 = 2;
    cout << canReach(n2, s2);
    
    std::cout << "\nFIN\n";
    return 0;
}
