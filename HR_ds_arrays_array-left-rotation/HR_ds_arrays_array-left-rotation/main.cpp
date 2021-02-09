//
//  main.cpp
//  HR_ds_arrays_array-left-rotation
//
//  Created by Jose Mari Syjuco on 9/2/21.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;


vector<int> rotateLeft(int d, vector<int> arr) {
    
    printf("%d\n", arr.size());
    
    vector<int> ans;
    int idx = d;
    while (ans.size() != arr.size()) {
        if (idx == arr.size()) {
            idx = 0;
            ans.push_back(arr[idx]);
        } else {
            ans.push_back(arr[idx]);
        }
        idx++;
    }
    
    for (auto i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return ans;
}

int main () {
    vector<int> arr = {1, 2, 3, 4, 5};
    rotateLeft(4, arr);
    return 0;
}

//4
//1 2 3 4 5

//5 1 2 3 4
