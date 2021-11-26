//
//  main.cpp
//  Merge Intervals
//
//  Created by Jose Mari Syjuco on 27/11/21.
//

#include <iostream>
#include <vector>

using namespace std;

bool comparator(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    vector<vector<int>> sortedIntervals = intervals;
    sort(sortedIntervals.begin(), sortedIntervals.end(), comparator);
    
    vector<vector<int>> ans;
    
    vector<int> first = sortedIntervals[0];
    int intervalStart = first[0];
    int intervalEnd = first[1];
    
    for (int i = 1; i < intervals.size(); ++i) {
        vector<int> current = sortedIntervals[i];
        
        if (intervalEnd < current[0]) {
            vector<int> nonOverlapping = { intervalStart, intervalEnd };
            ans.push_back(nonOverlapping);
            
            intervalStart = current[0];
            intervalEnd = current[1];
        } else if (intervalEnd >= current[0] && current[1] > intervalEnd) {
            intervalEnd = current[1];
        }
    }
    
    vector<int> lastPair = { intervalStart, intervalEnd };
    ans.push_back(lastPair);
    return ans;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> n1 = { {1,3}, {2,6}, {8,10}, {15,18} };
    vector<vector<int>> ans1 = mergeIntervals(n1);
    cout << "1:\n";
    for (auto a : ans1) cout << a[0] << ", " << a[1] << "\n";
    
    cout << "2:\n";
    vector<vector<int>> n2 = { {1,4}, {4,5} };
    vector<vector<int>> ans2 = mergeIntervals(n2);
    for (auto a : ans2) cout << a[0] << ", " << a[1] << "\n";
    std::cout << "FIN\n";
    return 0;
}
