//
//  main.cpp
//  11172
//
//  Created by Jose Mari Prim Syjuco on 2/2/20.
//  Copyright © 2020 Jose Mari Prim Syjuco. All rights reserved.
//

#include <iostream>

int main() {
    int TC, a, b;
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d %d", &a, &b);
        if (a == b) printf("%c\n", '=');
        else printf("%c\n", a < b ? '<' : '>');
    }
    return 0;
}
