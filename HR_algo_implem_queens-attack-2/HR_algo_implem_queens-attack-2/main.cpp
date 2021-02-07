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

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            GRID[i][j] = 0;
    
    GRID[r_q][c_q] = 9;
    
    for (int i = 0; i < obstacles.size(); ++i) {
        int r = obstacles[i][0];
        int c = obstacles[i][1];
        GRID[r][c] = -1;
//        for (int j = 0; j < obstacles[i].size(); ++j) {
//            printf("%d ", obstacles[i][j]);
//        }
//        printf("\n");
    }
//    printf("\n");
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d ", GRID[i][j]);
        }
        printf("\n");
    }
    
    return 1;
}

int main() {
    queensAttack(5, 3, 4, 3, {{5,5}, {4,2}, {2,3}});
    return 0;
}
