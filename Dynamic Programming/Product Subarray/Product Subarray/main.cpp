//
//  main.cpp
//  Product Subarray
//
//  Created by Jose Mari Syjuco on 4/12/21.
//

#include <iostream>
#include <vector>

using namespace std;

int maxProduct(vector<int>& nums) {
    int N = (int)nums.size();
    
    int minSoFar = nums[0];
    int maxSoFar = nums[0];
    int ans = maxSoFar;
    
    for (int i = 1; i < N; ++i) {
        int current = nums[i];
        int currMin = current * minSoFar;
        int currMax = current * maxSoFar;
        
        // Max between: current VS currMin VS currMax
        int maxCurr = max(currMin, currMax);
        maxSoFar = max(maxCurr, current);
        
        // Min between: current VS currMin VS currMax
        int minCurr = min(currMin, currMax);
        minSoFar = min(minCurr, current);
        
        ans = max(ans, maxSoFar);
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    vector<int> n1 = {2,3,-2,4};
    cout << maxProduct(n1) << "\n";
    
    vector<int> n2 = {2-2,0,-1};
    cout << maxProduct(n2) << "\n";
    
    vector<int> n3 = {-2,-1,1,2};
    cout << maxProduct(n3) << "\n";
    
    vector<int> n4 = {2,3,1,1,1,1,4};
    cout << maxProduct(n4) << "\n";
    
    cout << "FIN\n";
    return 0;
}
