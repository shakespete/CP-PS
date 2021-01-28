//
//  main.cpp
//  HR_red_knight_shortest_path
//
//  Created by Jose Mari Syjuco on 28/1/21.
//
#include <stdio.h>
#include <string>

#define MAX_N 205

int grid[205][205];
int N = 0;
int tRow = 0;
int tCol = 0;
int minSteps = 40000;

void move(int curr_row, int curr_col, int steps, int vis[][205], const char** stepList) {
    if (curr_row == tRow && curr_col == tCol && steps < minSteps) {
        minSteps = steps;
    }
    // UL
    if (curr_row - 2 >= 0 && curr_col - 1 >= 0 &&
    (steps + 1 < vis[curr_row - 2][curr_col - 1] || vis[curr_row - 2][curr_col - 1] == 0)) {
        vis[curr_row - 2][curr_col - 1] = steps + 1;
        char dir[3] = "UL";
        stepList[steps] = dir;
        printf("%d: %s\n", steps, stepList[steps]);
        move(curr_row - 2, curr_col - 1, steps + 1, vis, stepList);
    }
    // UR
    if (curr_row - 2 >= 0 && curr_col + 1 <= N - 1 &&
    (steps + 1 < vis[curr_row - 2][curr_col + 1] || vis[curr_row - 2][curr_col + 1] == 0)) {
        vis[curr_row - 2][curr_col + 1] = steps + 1;
        char dir[3] = "UR";
        stepList[steps] = dir;
        printf("%d: %s\n", steps, stepList[steps]);
        move(curr_row - 2, curr_col + 1, steps + 1, vis, stepList);
    }
    // R
    if (curr_col + 2 <= N - 1 &&
    (steps + 1 < vis[curr_row][curr_col + 2] || vis[curr_row][curr_col + 2] == 0)) {
        vis[curr_row][curr_col + 2] = steps + 1;
        char dir[3] = "R";
        stepList[steps] = dir;
        printf("%d: %s\n", steps, stepList[steps]);
        move(curr_row, curr_col + 2, steps + 1, vis, stepList);
    }
    // LR
    if (curr_row + 2 <= N - 1 && curr_col + 1 <= N - 1 &&
    (steps + 1 < vis[curr_row + 2][curr_col + 1] || vis[curr_row + 2][curr_col + 1] == 0)) {
        vis[curr_row + 2][curr_col + 1] = steps + 1;
        char dir[3] = "LR";
        stepList[steps] = dir;
        printf("%d: %s\n", steps, stepList[steps]);
        move(curr_row + 2, curr_col + 1, steps + 1, vis, stepList);
    }
    // LL
    if (curr_row + 2 <= N - 1 && curr_col - 1 >= 0 &&
    (steps + 1 < vis[curr_row + 2][curr_col - 1] || vis[curr_row + 2][curr_col - 1] == 0)) {
        vis[curr_row + 2][curr_col - 1] = steps + 1;
        char dir[3] = "LL";
        stepList[steps] = dir;
        printf("%d: %s\n", steps, stepList[steps]);
        move(curr_row + 2, curr_col - 1, steps + 1, vis, stepList);
    }
    // L
    if (curr_col - 2 >= 0 &&
    (steps + 1 < vis[curr_row][curr_col - 2] || vis[curr_row][curr_col - 2] == 0)) {
        vis[curr_row][curr_col - 2] = steps + 1;
        char dir[3] = "L";
        stepList[steps] = dir;
        printf("%d: %s\n", steps, stepList[steps]);
        move(curr_row, curr_col - 2, steps + 1, vis, stepList);
    }
}

void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end) {
    N = n;
    tRow = i_end;
    tCol = j_end;
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            grid[i][j] = 0;
    
    grid[i_start][j_start] = -1;
    
    const char** stepList = new const char*[40000];
    move(i_start, j_start, 0, grid, stepList);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
    
    if (minSteps == 40000) printf("Impossible");
    else {
        printf("%d\n", minSteps);
        for (int i = 0; i < minSteps; ++i) {
            printf("STEP %d: %s\n", i, stepList[i]);
        }
        printf("\n");
    }
}

int main() {
    printShortestPath(7, 6, 6, 0, 1);
}
