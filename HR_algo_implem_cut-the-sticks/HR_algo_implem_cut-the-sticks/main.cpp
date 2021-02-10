//
//  main.cpp
//  HR_algo_implem_cut-the-sticks
//
//  Created by Jose Mari Syjuco on 3/2/21.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

void swap(int a, int b, int* A) {
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

int partition(int start, int end, int* A) {
    int pivot = A[end];
    int x = start - 1;
    for (int i = start; i <= end; ++i)
        if (A[i] < pivot) swap(++x, i, A);
        
    swap(++x, end, A);
    return x;
}

void quick_sort(int start, int end, int* A) {
    if (start < end) {
        int p = partition(start, end, A);
        quick_sort(start, p-1, A);
        quick_sort(p+1, end, A);
    }
}

// Complete the cutTheSticks function below.
vector<int> cutTheSticks(vector<int> arr) {
    int N = arr.size();
    int* A = new int[N];
    for (int i = 0; i < N; ++i) A[i] = arr[i];
    
    quick_sort(0, N - 1, A);
    
    int idx = 0;
    int ctr = N;
    int* temp = new int[N];
    temp[idx] = ctr;
    
    int el = A[0];
    for (int i = 0; i < N; ++i) {
        if (A[i] == el) --ctr;
        else if (A[i] > el) {
            temp[++idx] = ctr;
            el = A[i];
            --ctr;
        }
    }
    
    int len = idx + 1;
    vector<int> ans(len);
    for (int i = 0; i < len; ++i) ans[i] = temp[i];
    return ans;
}

int main(int argc, const char * argv[]) {
    int n = 8; // 6
    
//    int arr_temp[n] = {5, 4, 4, 2, 2, 8};  -> n = 6
    int arr_temp[8] = {1, 2, 3, 4, 3, 3, 2, 1};
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = (arr_temp[i]);
    }
    
    vector<int> result = cutTheSticks(arr);
    for (int i = 0; i < result.size(); i++) {
        printf("%d\n", result[i]);
    }
    return 0;
}
