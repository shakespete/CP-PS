//
//  main.cpp
//  HR_algo_search_missing-numbers
//
//  Created by Jose Mari Syjuco on 1/8/21.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

#define MAX_N 10005

using namespace std;

void merge(int p, int q, int r, vector<int> &arr) {
    int i, j, k;
    
    int n1 = q - p + 1;
    int n2 = r - q;
    
    int* L = new int[n1 + 1];
    int* R = new int[n2 + 2];
    
    for (i = 1; i <= n1; ++i) L[i] = arr[i + p - 1];
    for (j = 1; j <= n2; ++j) R[j] = arr[j + q];
    
    L[n1 + 1] = MAX_N;
    R[n2 + 1] = MAX_N;
    
    i = j = 1;
    for (k = p; k <= r; ++k) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
    }
}

void mergeSort(int p, int r, vector<int> &arr) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(p, q, arr);
        mergeSort(q + 1, r, arr);
        merge(p, q, r, arr);
    }
}

vector<int> missingNumbers(vector<int> arr, vector<int> brr) {
    vector<int> res;
    
    int N = (int) arr.size();
    mergeSort(0, N - 1, arr);
    for (int i = 0; i < N; ++i) printf("%d ", arr[i]);
    printf("\n");
    
    int M = (int) brr.size();
    mergeSort(0, M - 1, brr);
    for (int i = 0; i < M; ++i) printf("%d ", brr[i]);
    printf("\n");
    
    int diff = M - N;
    int counter = 0;
    for (int i = 0; i < M; ++i) {
        int j = i - counter;
        
        if (arr[j] != brr[i]) {
            int resSize = (int)res.size();
            if (resSize > 1 && res[resSize - 1] != brr[i]) {
                res.push_back(brr[i]);
                counter++;
            } else {
                res.push_back(brr[i]);
                counter++;
            }
        }
        if (diff == counter) break;
    }
    return res;
}

int main() {
//    vector<int> arr = { 203, 204, 205, 206, 207, 208, 203, 204, 205, 206 };
//    vector<int> brr = { 203, 204, 204, 205, 206, 207, 205, 208, 203, 206, 205, 206, 204 };
//    vector<int> ans = missingNumbers(arr, brr);
    
    vector<int> arr = { 11, 4, 11, 7, 13, 4, 12, 11, 10, 14 };
    vector<int> brr = { 11, 4, 11, 7, 3, 7, 10, 13, 4, 8, 12, 11, 10, 14, 12 };
    vector<int> ans = missingNumbers(arr, brr);
    
    for (int i = 0; i < ans.size(); ++i) printf("%d ", ans[i]);
    printf("\n");
    
    return 0;
}

// 203 203 204 204 --- 205 205 --- 206 206 --- 207 208
// 203 203 204 204 204 205 205 205 206 206 206 207 208
