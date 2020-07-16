//
//  main.cpp
//  573
//
//  Created by Jose Mari Syjuco on 16/7/20.
//  Copyright © 2020 Jose Mari Syjuco. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int d;
    float H, U, D, F, h, c, f;
    while (true) {
        scanf("%f %f %f %f", &H, &U, &D, &F);
        if (H == 0) break;
        
        d = 1;                        // day
        c = U;                        // climbing distance
        h = 0.0;                      // height climbed
        f = (float)(U * F) / 100.0;   // fatigue
        
        while (h < H || h >= 0) {
            // printf("Day %d---------\n", d);
            if (d != 1 && c > 0) c -= f;
            // printf("Distance Climbed: %.2f\n", c);
            
            h += c;
            // printf("Height after climbing: %.2f\n", h);
            
            if (h > H) {
                printf("success on day %d\n", d);
                break;
            } else if (h < 0) {
                printf("failure on day %d\n", d);
                break;
            } else {
                h -= D;
                // printf("Height after sliding: %.2f\n", h);
                if (h < 0) {
                    printf("failure on day %d\n", d);
                    break;
                }
                ++d;
            }
        }
    }
    return 0;
}
