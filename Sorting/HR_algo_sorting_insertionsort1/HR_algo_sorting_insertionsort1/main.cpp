//
//  main.cpp
//  HR_algo_sorting_insertionsort1
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
            for (int j = 0; j < n; ++j) printf("%d ", arr[j]);
            printf("\n");
            break;
        } else {
            arr[i] = arr[i - 1];
            
            for (int j = 0; j < n; ++j) printf("%d ", arr[j]);
            printf("\n");
        }
        --i;
    }
}


int main() {
    vector<int> arr = {2, 4, 6, 8, 3};
    insertionSort1(5, arr);
    return 0;
}

// 5
// 2 4 6 8 3

// 2 4 6 8 8
// 2 4 6 6 8
// 2 4 4 6 8
// 2 3 4 6 8
