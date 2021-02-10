//
//  main.cpp
//  HR_algo_warmup_birthday-cake-candles
//
//  Created by Jose Mari Syjuco on 10/2/21.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

void swap(int x, int y, int* A) {
    int temp = A[x];
    A[x] = A[y];
    A[y] = temp;
}

int partition(int start, int end, int* A) {
    int pivot = A[end];
    int x = start - 1;
    for (int i = start; i <= end; ++i)
        if (A[i] > pivot)
            swap(++x, i, A);
    swap(++x, end, A);
    return x;
}

void quick_sort(int start, int end, int* A) {
    if (start < end) {
        int p = partition(start, end, A);
        quick_sort(start, p - 1, A);
        quick_sort(p + 1, end, A);
    }
}


#define MAX_N 1000

void merge(int* A, int p, int q, int r) {
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    int* L = new int[n1 + 1];
    int* R = new int[n2 + 1];

    for (i = 1; i <= n1; ++i) L[i] = A[p + i - 1];
    for (j = 1; j <= n2; ++j) R[j] = A[q + j];

    L[n1 + 1] = MAX_N;
    R[n2 + 1] = MAX_N;

    i = 1;
    j = 1;
    for (k = p; k <= r; ++k) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
    }
}


void merge_sort(int* A, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int birthdayCakeCandles(vector<int> candles) {
    size_t N = candles.size();
    printf("%lu\n", N);
    
    int* arr = new int[N];
    copy(candles.begin(), candles.end(), arr);
//    for (int i = 0; i < N; ++i) arr[i] = candles[i];
    
    for (int i = 0; i < N; ++i) printf("%d ", arr[i]);
    printf("\n");
    
    
    
//    quick_sort(0, N - 1, arr);
    merge_sort(arr, 0, N - 1);
    for (int i = 0; i < N; ++i) printf("%d ", arr[i]);
    printf("\n");
//    int tallest = arr[0];
    int tallest = arr[N - 1];
    
    int ans = 0;
    int idx = N - 1;
    while (tallest == arr[idx]) {
        ans++;
        idx--;
    }
    return ans;
}

int main () {
    vector<int> candles = {3, 2, 1, 3};
    int ans = birthdayCakeCandles(candles);
    printf("%d\n", ans);
    return 0;
}

