//
//  main.cpp
//  HR_algo_graph_theory_ctci-connected-cell-in-a-grid
//
//  Created by Jose Mari Syjuco on 28/7/21.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int ans = 0;
void traverse(int row, int col, int n, int m, int** &visited, vector<vector<int>> grid, int maxRegion) {
    if (maxRegion > ans) ans = maxRegion;
    
//    int[] rowDelta = {-1, -1, -1, 0, 1, 1, 1, 0};
//    int[] colDelta = {-1, 0, 1, 1, 1, 0, -1, -1};
    
    int rDelta[] = { -1, 0, 1};
    int cDelta[] = { -1, 0, 1};
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (row + rDelta[i]) {
                
            }
        }
    }
    
    // TOP
    if (row - 1 >= 0 && grid[row - 1][col] == 1 && visited[row - 1][col] == 0) {
        visited[row - 1][col] = 1;
//        printf("T: %d\n", maxRegion + 1);
        traverse(row - 1, col, n, m, visited, grid, maxRegion + 1);
        visited[row - 1][col] = 0;
    }
    // TOP RIGHT
    if (row - 1 >= 0 && col + 1 < m && grid[row - 1][col + 1] == 1 && visited[row - 1][col + 1] == 0) {
        visited[row - 1][col + 1] = 1;
//        printf("TR: %d\n", maxRegion + 1);
        traverse(row - 1, col + 1, n, m, visited, grid, maxRegion + 1);
        visited[row - 1][col + 1] = 0;
    }
    // RIGHT
    if (col + 1 < m && grid[row][col + 1] == 1 && visited[row][col + 1] == 0) {
        visited[row][col + 1] = 1;
//        printf("R: %d\n", maxRegion + 1);
        traverse(row, col + 1, n, m, visited, grid, maxRegion + 1);
        visited[row][col + 1] = 0;
    }
    // BOTTOM RIGHT
    if (row + 1 < n && col + 1 < m && grid[row + 1][col + 1] == 1 && visited[row + 1][col + 1] == 0) {
        visited[row + 1][col + 1] = 1;
//        printf("BR: %d\n", maxRegion + 1);
        traverse(row + 1, col + 1, n, m, visited, grid, maxRegion + 1);
        visited[row + 1][col + 1] = 0;
    }
    // BOTTOM
    if (row + 1 < n && grid[row + 1][col] == 1 && visited[row + 1][col] == 0) {
        visited[row + 1][col] = 1;
//        printf("B: %d\n", maxRegion + 1);
        traverse(row + 1, col, n, m, visited, grid, maxRegion + 1);
        visited[row + 1][col] = 0;
    }
    // BOTTOM LEFT
    if (row + 1 < n && col - 1 >= 0 && grid[row + 1][col - 1] == 1 && visited[row + 1][col - 1] == 0) {
        visited[row + 1][col - 1] = 1;
//        printf("BL: %d\n", maxRegion + 1);
        traverse(row + 1, col - 1, n, m, visited, grid, maxRegion + 1);
        visited[row + 1][col - 1] = 0;
    }
    // LEFT
    if (col - 1 >= 0 && grid[row][col - 1] == 1 && visited[row][col - 1] == 0) {
        visited[row][col - 1] = 1;
//        printf("L: %d\n", maxRegion + 1);
        traverse(row, col - 1, n, m, visited, grid, maxRegion + 1);
        visited[row][col - 1] = 0;
    }
    // TOP LEFT
    if (row - 1 >= 0 && col - 1 >= 0 && grid[row - 1][col - 1] == 1 && visited[row - 1][col - 1] == 0) {
        visited[row - 1][col - 1] = 1;
//        printf("TL: %d\n", maxRegion + 1);
        traverse(row - 1, col - 1, n, m, visited, grid, maxRegion + 1);
        visited[row - 1][col - 1] = 0;
    }
}

int maxRegion(vector<vector<int>> grid) {
    int n = (int)grid.size();
    int m = n > 0 ? (int)grid[0].size() : 0;
    
//    for (auto& row: grid) {
//        for (int& col: row) printf("%d ", col);
//        printf("\n");
//    }
    
    ans = 0;
    int** visited = new int*[n];
    for (int i = 0; i < n; ++i) visited[i] = new int[m]{0};
    
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            printf("%d ", visited[i][j]);
//        }
//        printf("\n");
//    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 1 && visited[i][j] == 0) {
                visited[i][j] = 1;
                traverse(i, j, n, m, visited, grid, 1);
            }
        }
    }
    
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            printf("%d ", visited[i][j]);
//        }
//        printf("\n");
//    }
    return ans;
}

int main(int argc, const char * argv[]) {
    

    vector<vector<int>> grid_2(5);
    grid_2[0] = { 0, 0, 1, 1 };
    grid_2[1] = { 0, 0, 1, 0 };
    grid_2[2] = { 0, 1, 1, 0 };
    grid_2[3] = { 0, 1, 0, 0 };
    grid_2[4] = { 1, 1, 0, 0 };
    
    int ans2 = maxRegion(grid_2);
    printf("%d\n", ans2);
    
    vector<vector<int>> grid_3(5);
    grid_3[0] = { 1, 0, 1, 1, 0 };
    grid_3[1] = { 1, 1, 0, 0, 1 };
    grid_3[2] = { 0, 1, 1, 1, 0 };
    grid_3[3] = { 0, 0, 0, 0, 1 };
    grid_3[4] = { 1, 1, 1, 0, 0 };

    int ans3 = maxRegion(grid_3);
    printf("%d\n", ans3);

    vector<vector<int>> grid_1(4);
    grid_1[0] = { 1, 1, 0, 0 };
    grid_1[1] = { 0, 1, 1, 0 };
    grid_1[2] = { 0, 0, 1, 0 };
    grid_1[3] = { 1, 0, 0, 0 };

    int ans1 = maxRegion(grid_1);
    printf("%d\n", ans1);
    
    return 0;
}
