//
//  main.cpp
//  Interval Intersection
//
//  Created by Jose Mari Syjuco on 24/11/21.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>>& first, vector<vector<int>>& second) {
    int N = (int)first.size();
    int M = (int)second.size();
    
    vector<vector<int>> ans;
    
    int i = 0;
    int j = 0;
    while (i < N && j < M) {
        vector<int> A = first[i];
        vector<int> B = second[j];
        int floor = max(A[0], B[0]);
        int ceil = min(A[1], B[1]);
        
        if (ceil >= floor) {
            vector<int> interval = { floor, ceil };
            ans.push_back(interval);
        }
        
        if (A[1] < B[1]) i++;
        else j++;
    }
    return ans;
};


int main() {
    vector<vector<int>> first = {{0,2}, {5,10}, {13,23}, {24,25}};
    vector<vector<int>> second = {{1,5}, {8,12}, {15,24}, {25,26}};
    vector<vector<int>> res = intervalIntersection(first, second);
    
    for (auto pair : res) {
        cout << pair[0] << ", " << pair[1] << "\n";
    }
    cout << "FIN\n";
    return 0;
}
