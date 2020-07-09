#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int K, N, M, x, y;
    
    while (true) {
        scanf("%d", &K);
        if (K == 0) break;
        
        scanf("%d %d", &N, &M);
        for (int i = 0; i < K; ++i) {
            scanf("%d %d", &x, &y);
            
            if (x == N || y == M) {
                printf("divisa\n");
            } else if (y > M) {
                if (x < N) printf("NO\n");
                else printf("NE\n");
            } else {
                if (x < N) printf("SO\n");
                else printf("SE\n");
            }
        }
    }
    return 0;
}
