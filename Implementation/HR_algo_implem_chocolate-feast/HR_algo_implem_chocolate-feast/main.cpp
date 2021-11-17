//
//  main.cpp
//  HR_algo_implem_chocolate-feast
//
//  Created by Jose Mari Syjuco on 4/2/21.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int chocolateFeast(int n, int c, int m) {
    int bars = 0;
    int eatIdx = 0;
    int wrappers = 0;
    int* eaten = new int[n];

    bars = n / c;
    eaten[eatIdx++] = bars;
    wrappers += bars;
    
    while (bars >= 0 && wrappers >= m) {
        bars -= eaten[eatIdx - 1];
        bars += wrappers / m;
        eaten[eatIdx++] = bars;
        wrappers -= bars * m;
        wrappers += bars;
    }
    
    int ans = 0;
    for (int i = 0; i < eatIdx; ++i) ans += eaten[i];
    printf("%d\n", ans);
    return ans;
}

int main() {
    chocolateFeast(15, 3, 2);
    chocolateFeast(10, 2, 5);
    chocolateFeast(12, 4, 4);
    chocolateFeast(6, 2, 2);
    return 0;
}
