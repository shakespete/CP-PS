//
//  main.cpp
//  HR_algo_implem_picking-numbers
//
//  Created by Jose Mari Syjuco on 28/8/21.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int pickingNumbers(vector<int> a) {
    sort(a.begin(), a.end());
    
    int ans = 0;
    int len = 0;
    int floor = -1;
    for (int i = 1; i < a.size(); ++i) {
        if (floor == -1) floor = a[i];
        if (a[i] - a[i - 1] <= 1 && a[i] - floor <= 1) len++;
        else {
            if (len > ans) ans = len;
            floor = a[i];
            len = 0;
        };
    }
    return ans + 1;
}

int main() {
    vector<int> grid(6);
    grid = { 1, 2, 2, 3, 1, 2 };
    
    int ans = pickingNumbers(grid);
    printf("%d\n", ans);
    return 0;
}
