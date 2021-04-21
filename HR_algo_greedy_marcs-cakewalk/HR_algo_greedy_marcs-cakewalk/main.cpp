//
//  main.cpp
//  HR_algo_greedy_marcs-cakewalk
//
//  Created by Jose Mari Syjuco on 24/2/21.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

void swap(int x, int y, int* A) {
    int temp = A[x];
    A[x] = A[y];
    A[y] = temp;
}

void bubble_sort(int N, int* A) {
    for (int i = 1; i < N; ++i)
        for (int j = 0; j < N - i; ++j)
            if (A[j] < A[j + 1])
                swap(j, j + 1, A);
}

long marcsCakewalk(vector<int> calorie) {
    unsigned long N = calorie.size();
    int* calArr = &calorie[0];
    
    long miles = 0;
    
    bubble_sort(N, calArr);
    for (int i = 0; i < N; ++i) {
//        printf("%d %d\n", calArr[i], i);
        miles += pow(2, i) * calArr[i];
    }
    printf("Miles: %ld\n", miles);
    return miles;
}

int main() {
    marcsCakewalk({7, 4, 9, 6});
    marcsCakewalk({801, 234, 536, 747, 172, 590, 833, 847, 509, 429, 666, 411, 609, 894, 348, 254 ,814, 767 ,647 ,965, 711 ,801, 852, 781, 972, 390, 218, 290, 508, 174, 55, 714, 442, 284, 745, 872 ,46 ,131, 833, 315});
    return 0;
}

// 4
// 7 4 9 6

// 79
