//
//  main.cpp
//  Robbers
//
//  Created by Jose Mari Syjuco on 1/12/21.
//

#include <iostream>
#include <vector>

using namespace std;

// Time: O(n) | Space: O(1)
int robbers(vector<int>& nums) {
    int N = (int)nums.size();
    if (N == 1) return nums[0];
    
    nums[1] = max(nums[0], nums[1]);
    for (int i = 2; i < N; ++i) {
        int lootA = nums[i - 1];
        int lootB = nums[i - 2] + nums[i];
        nums[i] = max(lootA, lootB);
    }
    
    return nums[N - 1];
}

int main(int argc, const char * argv[]) {
    vector<int> n1 = {1,2,3,1};
    cout << robbers(n1) << "\n";
    
    vector<int> n2 = {2,7,9,3,1};
    cout << robbers(n2) << "\n";
    
    vector<int> n3 = {2,1,1,2};
    cout << robbers(n3) << "\n";
    
    cout << "FIN\n";
    return 0;
}
