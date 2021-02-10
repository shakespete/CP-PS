//
//  main.cpp
//  HR_red_knight_shortest_path
//
//  Created by Jose Mari Syjuco on 28/1/21.
//
#include <stdio.h>
#include <string>

#define MAX_N 205

int grid[MAX_N][MAX_N];
int N = 0;
int tRow = 0;
int tCol = 0;
int minSteps = MAX_N*MAX_N;
const char** ans = new const char*[MAX_N*MAX_N];

void str_copy(char* des, const char* src) {
    while (*src != '\0') *des++ = *src++;
    *des = '\0';
}

void move(int curr_row, int curr_col, int steps, int vis[][205], const char** stepList) {
    // Base Case:
    if (curr_row == tRow && curr_col == tCol && steps < minSteps) {
        minSteps = steps;
        for (int i = 0; i < minSteps; ++i) {
            ans[i] = stepList[i];
        }
    }
    // UL
    if (curr_row - 2 >= 0 && curr_col - 1 >= 0 &&
    (steps + 1 < vis[curr_row - 2][curr_col - 1] || vis[curr_row - 2][curr_col - 1] == 0)) {
        vis[curr_row - 2][curr_col - 1] = steps + 1;
        
        char source[3] = "UL";
        char* destination = new char[3];
        str_copy(destination, source);
        stepList[steps] = destination;
        move(curr_row - 2, curr_col - 1, steps + 1, vis, stepList);
    }
    // UR
    if (curr_row - 2 >= 0 && curr_col + 1 <= N - 1 &&
    (steps + 1 < vis[curr_row - 2][curr_col + 1] || vis[curr_row - 2][curr_col + 1] == 0)) {
        vis[curr_row - 2][curr_col + 1] = steps + 1;
        char source[3] = "UR";
        char* destination = new char[3];
        str_copy(destination, source);
        stepList[steps] = destination;
        move(curr_row - 2, curr_col + 1, steps + 1, vis, stepList);
    }
    // R
    if (curr_col + 2 <= N - 1 &&
    (steps + 1 < vis[curr_row][curr_col + 2] || vis[curr_row][curr_col + 2] == 0)) {
        vis[curr_row][curr_col + 2] = steps + 1;
        char source[3] = "R";
        char* destination = new char[3];
        str_copy(destination, source);
        stepList[steps] = destination;
        move(curr_row, curr_col + 2, steps + 1, vis, stepList);
    }
    // LR
    if (curr_row + 2 <= N - 1 && curr_col + 1 <= N - 1 &&
    (steps + 1 < vis[curr_row + 2][curr_col + 1] || vis[curr_row + 2][curr_col + 1] == 0)) {
        vis[curr_row + 2][curr_col + 1] = steps + 1;
        char source[3] = "LR";
        char* destination = new char[3];
        str_copy(destination, source);
        stepList[steps] = destination;
        move(curr_row + 2, curr_col + 1, steps + 1, vis, stepList);
    }
    // LL
    if (curr_row + 2 <= N - 1 && curr_col - 1 >= 0 &&
    (steps + 1 < vis[curr_row + 2][curr_col - 1] || vis[curr_row + 2][curr_col - 1] == 0)) {
        vis[curr_row + 2][curr_col - 1] = steps + 1;
        char source[3] = "LL";
        char* destination = new char[3];
        str_copy(destination, source);
        stepList[steps] = destination;
        move(curr_row + 2, curr_col - 1, steps + 1, vis, stepList);
    }
    // L
    if (curr_col - 2 >= 0 &&
    (steps + 1 < vis[curr_row][curr_col - 2] || vis[curr_row][curr_col - 2] == 0)) {
        vis[curr_row][curr_col - 2] = steps + 1;
        char source[3] = "L";
        char* destination = new char[3];
        str_copy(destination, source);
        stepList[steps] = destination;
        move(curr_row, curr_col - 2, steps + 1, vis, stepList);
    }
}

void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end) {
    N = n;
    tRow = i_end;
    tCol = j_end;
    minSteps = MAX_N*MAX_N;
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            grid[i][j] = 0;
    
    grid[i_start][j_start] = -1;
    const char** stepList = new const char*[MAX_N*MAX_N];
    move(i_start, j_start, 0, grid, stepList);

    if (minSteps == MAX_N*MAX_N) printf("Impossible\n");
    else {
        printf("%d\n", minSteps);
        for (int i = 0; i < minSteps; ++i) {
            printf("%s ", ans[i]);
        }
        printf("\n");
    }
}

int main() {
    printShortestPath(7, 6, 6, 0, 1);
    printShortestPath(6, 5, 0, 1, 5);
    printShortestPath(7, 0, 3, 4, 3);
}
