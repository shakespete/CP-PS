//
//  main.cpp
//  HR_algo_greedy_grid-challenge
//
//  Created by Jose Mari Syjuco on 16/9/21.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string gridChallenge(vector<string> grid) {
    for (int i = 0; i < grid.size(); ++i) sort(grid[i].begin(), grid[i].end());
    for (int i = 1; i < grid.size(); ++i)
        for (int j = 0; j < grid[i].size(); ++j)
            if (grid[i][j] < grid[i - 1][j])
                return "NO";
    return "YES";
//    for (int i = 0; i < grid.size(); ++i) printf("%s\n", grid[i].c_str());
//    return "YES";
}

int main(int argc, const char * argv[]) {
    vector<string> grid(5);
    grid[0] = "ebacd";
    grid[1] = "fghij";
    grid[2] = "olmkn";
    grid[3] = "trpqs";
    grid[4] = "xywuv";
    string ans = gridChallenge(grid);
    printf("%s\n", ans.c_str());
    return 0;
}
