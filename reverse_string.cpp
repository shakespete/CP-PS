//
//  main.cpp
//  String Reverse
//
//  Created by Jose Mari Syjuco on 3/8/20.
//  Copyright © 2020 Jose Mari Syjuco. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void reverse_string(char* str) {
    int size = 0;
    while(str[size] != '\0') size++;
    
    for (int i = 0; i < size / 2; i++)
    {
        char temp = str[i];
        str[i] = str[size-i-1];
        str[size-i-1] = temp;
    }
}


int main() {
    char* str = new char[10];
    scanf("%s", str);
    reverse_string(str);
    printf("%s\n", str);
    return 0;
}
