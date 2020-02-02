//
//  main.cpp
//  11172
//
//  Created by Jose Mari Prim Syjuco on 2/2/20.
//  Copyright © 2020 Jose Mari Prim Syjuco. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int TC, a, b;
    int i = 0;
    scanf("%d", &TC);
    while (i < TC) {
        scanf("%d %d", &a, &b);
        printf("%c\n", a < b ? '<' : a == b ? '=' : '>');
    }
    return 0;
}
