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


// Top-down with memoization O(n^2)
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

// Bottom-up O(n^2)
int bottomUpCutRod(vector<int> &price) {
    int N = (int)price.size();
    int rodLength = N - 1;
    vector<int> maxRevenue(N, -1);
    maxRevenue[0] = 0;
    
    for (int j = 1; j <= rodLength; ++j) {
        int revenue = -1;
        printf(" ****** %d inch rod ****** \n", j);
        
        for (int lenA = 1; lenA <= j; ++lenA) {
            int lenB = j - lenA;
            printf("1st length: %d\n", lenA);
            printf("2nd length: %d\n", lenB);
            
            if (price[lenA] + maxRevenue[lenB] > revenue) {
                revenue = price[lenA] + maxRevenue[lenB];
                printf("Higher revenue cuts: %d + %d => %d\n", lenA, lenB, revenue);
            }
        }
        
        printf("----------- Max revenue for %d inch rod: %d -----------\n", j, revenue);
        maxRevenue[j] = revenue;
    }
    return maxRevenue[rodLength];
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
