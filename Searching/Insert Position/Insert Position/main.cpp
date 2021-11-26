//
//  main.cpp
//  Insert Position
//
//  Created by Jose Mari Syjuco on 26/11/21.
//

#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int floor = 0;
    int ceil = (int)nums.size() - 1;
    
    int mid;
    while (floor <= ceil) {
        mid = (floor + ceil) / 2;
        if (target == nums[mid]) return mid;
        else if (target < nums[mid]) ceil = mid - 1;
        else floor = mid + 1;
    }
    return floor;
}

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1,3,5,6};
    int ans1 = searchInsert(nums1, 5);
    cout << ans1 << "\n";
    
    int ans2 = searchInsert(nums1, 2);
    cout << ans2 << "\n";
    
    int ans3 = searchInsert(nums1, 7);
    cout << ans3 << "\n";
    
    vector<int> nums4 = {0};
    int ans4 = searchInsert(nums4, 0);
    cout << ans4 << "\n";
    
    cout << "FIN\n";
    return 0;
}
