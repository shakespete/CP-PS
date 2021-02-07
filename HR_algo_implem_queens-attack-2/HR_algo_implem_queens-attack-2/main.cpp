//
//  main.cpp
//  HR_algo_implem_queens-attack-2
//
//  Created by Jose Mari Syjuco on 7/2/21.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;
vector<string> split_string(string);

int GRID[100005][100005];
int ans = 0;
int N = 0;

void traverse(int r, int c, int mRow, int mCol) {
    int y = r + mRow;
    int x = c + mCol;
    if (
        (y > 0 && y <= N) &&
        (x > 0 && x <= N) &&
        GRID[y][x] == 0
       ) {
        GRID[y][x] = 1;
        ans++;
        traverse(y, x, mRow, mCol);
    }
}

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    // #1 Reset board
    ans = 0;
    N = n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            GRID[i][j] = 0;
    
    // #2 Set start pos
    GRID[r_q][c_q] = 9;
    
    // #3 Set obstacles
    for (int i = 0; i < obstacles.size(); ++i) {
        int r = obstacles[i][0];
        int c = obstacles[i][1];
        GRID[r][c] = -1;
    }
    
    // Moves list
    int rowMoves[] = {-1, 0, 1};
    int colMoves[] = {-1, 0, 1};
    
    // #4 Start initial moves
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            traverse(r_q, c_q, rowMoves[i], colMoves[j]);
        }
    }
    
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d ", GRID[i][j]);
        }
        printf("\n");
    }
    printf("%d\n", ans);
    return 1;
}

int main() {
    queensAttack(5, 3, 4, 3, {{5,5}, {4,2}, {2,3}});
    return 0;
}
