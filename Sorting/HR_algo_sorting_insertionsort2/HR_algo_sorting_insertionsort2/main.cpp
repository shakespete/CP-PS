//
//  main.cpp
//  HR_algo_sorting_insertionsort2
//
//  Created by Jose Mari Syjuco on 9/2/21.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

void insertionSort1(int n, vector<int> arr) {
    int x = arr[n - 1];
    
    int i = n - 1;
    while (i >= 0) {
        if (x > arr[i - 1] ) {
            arr[i] = x;
//            for (int j = 0; j < n; ++j) printf("%d ", arr[j]);
//            printf("\n");
            break;
        } else {
            arr[i] = arr[i - 1];
            
//            for (int j = 0; j < n; ++j) printf("%d ", arr[j]);
//            printf("\n");
        }
        --i;
    }
}

void insertionSort2(int n, vector<int> arr) {
    int idx = 1;
    while (idx < n) {
        int x = arr[idx];
        int i = idx;
        while (i >= 0) {
            if (x > arr[i - 1] ) {
                arr[i] = x;
                break;
            } else {
                arr[i] = arr[i - 1];
            }
            --i;
        }
        for (int j = 0; j < n; ++j) printf("%d ", arr[j]);
        printf("\n");
        ++idx;
    }
}


int main(int argc, const char * argv[]) {
//    vector<int> arr = {2, 4, 6, 8, 3};
//    insertionSort1(5, arr);
    vector<int> arr = {1, 4, 3, 5, 6, 2};
    insertionSort2(6, arr);
    return 0;
}

// 6
// 1 4 3 5 6 2

//   x
// 1 4 3 5 6 2
//     x
// 1 3 4 5 6 2
//       x
// 1 3 4 5 6 2
// 1 3 4 5 6 2
// 1 2 3 4 5 6
