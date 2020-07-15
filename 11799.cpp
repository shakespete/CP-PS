//
//  main.cpp
//  11799
//
//  Created by Jose Mari Syjuco on 15/7/20.
//  Copyright © 2020 Jose Mari Syjuco. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int T, N, c, s;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        scanf("%d", &N);
        s = 0;
        for (int j = 0; j < N; ++j) {
            scanf("%d", &c);
            if (c > s) s = c;
        }
        printf("Case %d: %d\n", i, s); 
    }
    return 0;
}
