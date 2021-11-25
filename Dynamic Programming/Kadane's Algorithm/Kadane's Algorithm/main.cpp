//
//  main.cpp
//  Kadane's Algorithm
//
//  Created by Jose Mari Syjuco on 25/11/21.
//

#include <iostream>
#include <vector>

using namespace std;

// Time: O(n) | Space: O(1)
int kadanesAlgorithm(vector<int> nums) {
    int maxSoFar = nums[0];
    int maxSum = nums[0];
    
    for (int i = 1; i < nums.size(); ++i) {
        int valAtCurrIdx = nums[i];
        maxSoFar = max(maxSoFar + valAtCurrIdx, valAtCurrIdx);
        maxSum = max(maxSoFar, maxSum);
    }
    return maxSum;
}

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {-2,1,-3,4,-1,2,1,-5,4};
    int ans1 = kadanesAlgorithm(nums1);
    cout << ans1 << "\n";
    
    
    vector<int> nums2 = {5,4,-1,7,8};
    int ans2 = kadanesAlgorithm(nums2);
    cout << ans2;
    
    cout << "\nFIN\n";
    return 0;
}
