//
//  main.cpp
//  HR_algo_sorting_insertion-sort
//
//  Created by Jose Mari Syjuco on 1/8/21.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int insertion_sort(vector<int> arr) {
    int N = (int)arr.size();
    int ans = 0;
    for (int j = 1; j < N; ++j) {
        int moves = 0;
        int key = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] > key) {
            moves += 1;
            arr[i + 1] = arr[i];
            --i;
        }
        arr[i + 1] = key;
        printf("%d\n", moves);
        ans += moves;
    }
    printf("ANS: %d\n", ans);
    return ans;
}

int main() {
    vector<int> arr = { 4,3,2,1 };
    int size = (int)arr.size();

    for (int i = 0; i < size; ++i) printf("%d ", arr[i]);
    printf("\n");
    int res = insertion_sort(arr);
    for (int i = 0; i < size; ++i) printf("%d ", arr[i]);
    printf("\n%d\n", res);
    return 0;
}
