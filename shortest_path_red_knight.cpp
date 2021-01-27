#include <stdio.h>
#include <string>

#define MAX_N 205

int grid[205][205];
int N = 0;
int tRow = 0;
int tCol = 0;
int minSteps = 40000;

void move(int curr_row, int curr_col, int steps, int vis[][205]) {
    if (curr_row == tRow && curr_col == tCol && steps < minSteps) {
        minSteps = steps;
    }
    // UL
    if (curr_row - 2 >= 0 && curr_col - 1 >= 0 &&
        (steps < vis[curr_row - 2][curr_col - 1] || vis[curr_row - 2][curr_col - 1] == 0)) {
        vis[curr_row - 2][curr_col - 1] = steps + 1;
        move(curr_row - 2, curr_col - 1, steps + 1, vis);
        // vis[curr_row - 2][curr_col - 1] = steps;
    }
    // UR
    if (curr_row - 2 >= 0 && curr_col + 1 <= N - 1 &&
    (steps < vis[curr_row - 2][curr_col + 1] || vis[curr_row - 2][curr_col + 1] == 0)) {
        vis[curr_row - 2][curr_col + 1] = steps + 1;
        move(curr_row - 2, curr_col + 1, steps + 1, vis);
        // vis[curr_row - 2][curr_col + 1] = steps;
    }
    // R
    if (curr_col + 2 <= N - 1 &&
    (steps < vis[curr_row][curr_col + 2] || vis[curr_row][curr_col + 2] == 0)) {
        vis[curr_row][curr_col + 2] = steps + 1;
        move(curr_row, curr_col + 2, steps + 1, vis);
        // vis[curr_row][curr_col + 2] = steps;
    }
    // LR
    if (curr_row + 2 <= N - 1 && curr_col + 1 <= N - 1 &&
    (steps < vis[curr_row + 2][curr_col + 1] || vis[curr_row + 2][curr_col + 1] == 0)) {
        vis[curr_row + 2][curr_col + 1] = steps + 1;
        move(curr_row + 2, curr_col + 1, steps + 1, vis);
        // vis[curr_row + 2][curr_col + 1] = steps;
    }
    // LL
    if (curr_row + 2 <= N - 1 && curr_col - 1 >= 0 &&
    (steps < vis[curr_row + 2][curr_col - 1] || vis[curr_row + 2][curr_col - 1] == 0)) {
        vis[curr_row + 2][curr_col - 1] = steps + 1;
        move(curr_row + 2, curr_col - 1, steps + 1, vis);
        // vis[curr_row + 2][curr_col - 1] = steps;
    }
    // L
    if (curr_col - 2 >= 0 &&
    (steps < vis[curr_row][curr_col - 2] || vis[curr_row][curr_col - 2] == 0)) {
        vis[curr_row][curr_col - 2] = steps + 1;
        move(curr_row, curr_col - 2, steps + 1, vis);
        // vis[curr_row][curr_col - 2] = steps;
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
    
    char** steps = new char*[40000];
    
    move(i_start, j_start, 0, grid);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
    printf("STEPS: %d\n", minSteps);
    if (minSteps == 40000) printf("Impossible");
}

int main() {
    printShortestPath(7, 6, 6, 0, 1);
}
