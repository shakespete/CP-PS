//
//  main.cpp
//  GCJ_20_vestigium
//
//  Created by Jose Mari Syjuco on 7/8/21.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int* vestigium(int** grid, int N) {
    int k = 0;
    int r = 0;
    int c = 0;
    int* ans = new int[3];
    ans[0] = k;
    ans[1] = r;
    ans[2] = c;
    
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
    
    int T, N, k, r, c;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        scanf("%d", &N);
        k = r = c = 0;
        
        int* rowVis = new int[N]{0};
        int** rows = new int*[N];
        
        int* colVis = new int[N]{0};
        int** cols = new int*[N];
        
        for (int i = 0; i < N; ++i) {
            rows[i] = new int[N]{0};
            cols[i] = new int[N]{0};
        }
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int val;
                scanf("%d", &val);
                
                if (rowVis[i] == 0 && rows[i][val - 1] == 1) {
                    rowVis[i] = 1;
                    r++;
                }
                
                if (colVis[j] == 0 && cols[j][val - 1] == 1) {
                    colVis[j] = 1;
                    c++;
                }
                
                rows[i][val - 1] = 1;
                cols[j][val - 1] = 1;
                
                if (i == j) k += val;
            }
        }
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                printf("%d ", cols[i][j]);
            }
            printf("\n");
        }
        
//        int* ans = vestigium(grid, N);
        printf("Case #%d: %d %d %d\n", test_case, k, r, c);
    }
    return 0;
}
