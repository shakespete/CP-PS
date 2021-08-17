//
//  main.cpp
//  GCJ_20_vestigium
//
//  Created by Jose Mari Syjuco on 7/8/21.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

#include <time.h>

using namespace std;

int main() {
    clock_t start, end;
    start = clock();
    freopen("input.txt", "r", stdin);
    
    int T, N, k, r, c;
    scanf("%d", &T);
    
    for (int test_case = 1; test_case <= T; ++test_case) {
        scanf("%d", &N);
        k = r = c = 0;
        
        vector<int> rowVis(N, 0);
        vector<vector<int>> rows(N, vector<int>(N, 0));
        
        vector<int> colVis(N, 0);
        vector<vector<int>> cols(N, vector<int>(N, 0));
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int val;
                scanf("%d", &val);
                
                if (rowVis[i] != 1 && rows[i][val - 1] == 1) {
                    rowVis[i] = 1;
                    r++;
                }
                
                if (colVis[j] != 1 && cols[j][val - 1] == 1) {
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
        printf("Case #%d: %d %d %d\n", test_case, k, r, c);
    }
    
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    printf("Time taken: %.6fs\n", time_taken);
    
    return 0;
}
