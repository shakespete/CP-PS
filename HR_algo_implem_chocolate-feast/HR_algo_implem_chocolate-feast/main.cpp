//
//  main.cpp
//  HR_algo_implem_chocolate-feast
//
//  Created by Jose Mari Syjuco on 4/2/21.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int chocolateFeast(int n, int c, int m) {
    int leftOverCash = n % c;
    int bars = n / c;
    printf("Cash: %d\n", leftOverCash);
    printf("Bars: %d\n", bars);
    
    int wrappers = bars;
    printf("Wrappers: %d\n", wrappers);
    bars -= wrappers;
    printf("Remaining Bars: %d\n", bars);
    
    
    bars += wrappers / m;
    printf("New Bars: %d\n", bars);
    wrappers -= bars * m;
    printf("Remaining Wrappers: %d\n", wrappers);
    wrappers += bars;
    
    
    return 1;
}

int main() {
    chocolateFeast(15, 3, 2);
    return 0;
}
