//
//  main.cpp
//  HR_algo_warmup_birthday-cake-candles
//
//  Created by Jose Mari Syjuco on 10/2/21.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int birthdayCakeCandles(vector<int> candles) {
    int ans = 0;
    int tallest = 0;
    for (auto& it : candles) {
        printf("%d ", it);
        if (it > tallest) {
            tallest = it;
            ans = 1;
        } else if (it == tallest) {
            ans++;
        }
    }
    printf("\n");
    return ans;
}

int main () {
    vector<int> candles = {3, 2, 1, 3};
    int ans = birthdayCakeCandles(candles);
    printf("%d\n", ans);
    return 0;
}

