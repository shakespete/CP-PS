//
//  main.cpp
//  Only Single Element
//
//  Created by Jose Mari Syjuco on 23/11/21.
//

#include <iostream>
#include <vector>

using namespace std;

// Time: O(log(n)) | Space: O(1)
int onlySingleEl(vector<int>& nums) {
    int N = (int)nums.size();
    int floor = 0;
    int ceil = N - 1;
    
    while(floor < ceil) {
        int mid = (floor + ceil) / 2;
        if(mid - 1 >= 0 && nums[mid - 1] == nums[mid]) {
            bool lowerHalfIsEven = (mid - floor + 1) % 2 == 0; // Check if even
            if (lowerHalfIsEven) floor = mid + 1;
            else ceil = mid - 2;
        } else if (mid + 1 < N && nums[mid] == nums[mid + 1]) {
            bool upperHalfIsEven = (ceil - mid + 1) % 2 == 0; // Check if even
            if (upperHalfIsEven) ceil = mid - 1;
            else floor = mid + 2;
        } else {
            return nums[mid];
        }
    }
    return nums[ceil];
}

int main() {
    vector<int> prob1 = {1,1,2,3,3,4,4,8,8};
    int ans1 = onlySingleEl(prob1);
    cout << ans1 << "\n";
    
    vector<int> prob2 = {3,3,7,7,10,11,11};
    int ans2 = onlySingleEl(prob2);
    cout << ans2 << "\n";
    
    vector<int> prob3 = {1};
    int ans3 = onlySingleEl(prob3);
    cout << ans3 << "\n";
    return 0;
}
