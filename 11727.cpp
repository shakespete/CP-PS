//
//  main.cpp
//  11727
//
//  Created by Jose Mari Syjuco on 15/7/20.
//  Copyright © 2020 Jose Mari Syjuco. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int* A, int N) {
    for (int i = 1; i < N; ++i)
        for (int j = 0; j < N - i; ++j)
            if (A[j] > A[j + 1]) swap(&A[j], &A[j + 1]);
}

int main(int argc, const char * argv[]) {
    int T, x, y, z;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        scanf("%d %d %d", &x, &y, &z);
        int arr[3];
        arr[0] = x;
        arr[1] = y;
        arr[2] = z;
        bubble_sort(arr, 3);
        printf("Case %d: %d\n", i, arr[1]);
    }
    return 0;
}
