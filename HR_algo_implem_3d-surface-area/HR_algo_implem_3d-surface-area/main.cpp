//
//  main.cpp
//  HR_algo_implem_3d-surface-area
//
//  Created by Jose Mari Syjuco on 14/8/21.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int surfaceArea(vector<vector<int>> A) {
    int exterior = 0;
    int interior = 0;
    int H = (int) A.size();
    int W = (int) A[0].size();
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0) exterior += A[i][j];
            if (i == H - 1) exterior += A[i][j];
            if (j == 0) exterior += A[i][j];
            if (j == W - 1) exterior += A[i][j];
            
            if (j > 0) interior += abs(A[i][j] - A[i][j - 1]);
            if (i > 0) interior += abs(A[i][j] - A[i - 1][j]);
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    
    int top_bottom = H * W * 2;
    printf("TB: %d\n", top_bottom);
    printf("EX: %d\n", exterior);
    printf("IN: %d\n", interior);
    return exterior + interior + top_bottom;
}

int main() {
    vector<vector<int>> grid_1(3);
    grid_1[0] = { 1, 3, 4 };
    grid_1[1] = { 2, 2, 3 };
    grid_1[2] = { 1, 2, 4 };
    
    vector<vector<int>> grid_2(1);
    grid_2[0] = { 1 };
    
    int ans = surfaceArea(grid_1);
    printf("%d\n", ans);
    return 0;
}
