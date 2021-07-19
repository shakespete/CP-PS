//
//  main.cpp
//  HR_algo_recursion_the-power-sum
//
//  Created by Jose Mari Syjuco on 19/7/21.
//

#include <stdio.h>
#include <math.h>
using namespace std;

int getMaxRoot(int X, int rootVal) {
    long int root = (long int)pow(X, 1.0 / rootVal);
    return (int)root;
}


int ans;
void recurse(int X, int n, int r, int curr) {
//    printf("%d %d\n", r, curr);
    if (curr == X) {
//        printf("ANS!!!!!!!!!!!\n");
        ans++;
    }
    
    if (r == 0) return;
    if (curr > X) return;
    if (curr < X) {
        recurse(X, n, r - 1, curr + pow(r, n));
        recurse(X, n, r - 1, curr);
    }
}

int powerSum(int X, int N) {
    int root = getMaxRoot(X, N);
    ans = 0;
    recurse(X, N, root, 0);
    return ans;
}


int main(int argc, const char * argv[]) {
    int ans = powerSum(100, 2);
    printf("%d\n", ans);
    return 0;
}
