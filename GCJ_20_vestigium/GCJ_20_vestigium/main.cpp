//
//  main.cpp
//  GCJ_20_vestigium
//
//  Created by Jose Mari Syjuco on 7/8/21.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>


int T, N;
int* vestigium(int** grid) {
    int* ans = new int[3];
    ans[0] = 1;
    ans[1] = 2;
    ans[2] = 3;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        scanf("%d", &N);
        
        int** grid = new int*[N];
        for (int i = 0; i < N; ++i) {
            grid[i] = new int[N];
            for (int j = 0; j < N; ++j) {
                scanf("%d", &grid[i][j]);
            }
        }
        
        int* ans = vestigium(grid);
        printf("Case #%d: %d %d %d\n", test_case, ans[0], ans[1], ans[2]);
    }
    return 0;
}
