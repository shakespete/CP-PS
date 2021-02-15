//
//  main.cpp
//  HR_algo_search_icecream-parlor
//
//  Created by Jose Mari Syjuco on 15/2/21.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;


int traverse(int rem, int start, vector<int> arr) {
    for (int j = start; j < arr.size(); ++j) {
        if (rem - arr[j] == 0) return j;
    }
    return -1;
};
// Complete the icecreamParlor function below.
vector<int> icecreamParlor(int m, vector<int> arr) {
    // printf("%d\n", m);
    vector<int> ans(2);
    for (auto i = 0U; i < arr.size(); ++i) {
        if (arr[i] < m) {
            int remaining = m - arr[i];
            int johnny = traverse(remaining, i + 1, arr);
            if (johnny != -1) {
                // printf("Sunny: %d\n", i + 1);
                // printf("Johnny: %d\n", johnny + 1);
                ans[0] = i + 1;
                ans[1] = johnny + 1;
            }
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    return 0;
}

//2
//4
//5
//1 4 5 3 2
//4
//4
//2 2 4 3

//1 4
//1 2
