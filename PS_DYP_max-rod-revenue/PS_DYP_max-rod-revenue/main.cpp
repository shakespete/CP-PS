//
//  main.cpp
//  PS_DYP_max-rod-revenue
//
//  Created by Jose Mari Syjuco on 5/11/21.
//

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;


// Top-down with memoization
int memoizedCutRodAux(vector<int> &price, int n, vector<int> &revenue) {
    if (revenue[n] >= 0) return revenue[n];
    
    int r;
    if (n == 0) r = 0;
    else {
        r = -1;
        for (int i = 1; i <= n; ++i) {
            r = max(r, price[i] + memoizedCutRodAux(price, n - i, revenue));
        }
    }
    
    revenue[n] = r;
    return r;
}
int memoizedCutRod(vector<int> &price) {
    int N = (int)price.size();
    int rodLength = N - 1;
    vector<int> revenue(N, -1);
    return memoizedCutRodAux(price, rodLength, revenue);
}

// Bottom-up
int bottomUpCutRod(vector<int> &price) {
    int N = (int)price.size();
    int rodLength = N - 1;
    vector<int> revenue(N, -1);
    revenue[0] = 0;
    for (int j = 1; j <= rodLength; ++j) {
        int r = -1;
        printf("Max length: %d ------------- \n", j);
        for (int i = 1; i <= j; ++i) {
            printf("1st length: %d\n", i);
            printf("2nd length: %d\n", j - i);
            if (r < price[i] + revenue[j - i]) {
                r = price[i] + revenue[j - i];
                printf("Higher revenue lengths: %d + %d => %d\n", i, j - i, r);
            }
        }
        revenue[j] = r;
    }
    return revenue[rodLength];
}

int main() {
    vector<int> price{ 0, 1, 5, 8, 9 };
    int tbRev = memoizedCutRod(price);
    printf("%d\n", tbRev);
    int buRev = bottomUpCutRod(price);
    printf("%d\n", buRev);
    return 0;
}

// rod of length i       0 1 2 3 4
// price per length p(i) 0 1 5 8 9
