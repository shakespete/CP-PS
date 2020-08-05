//
//  main.cpp
//  Reverse Words
//
//  Created by Jose Mari Syjuco on 5/8/20.
//  Copyright © 2020 Jose Mari Syjuco. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

void reverseChar(string& str) {
    int leftIdx = 0;
    int rightIdx = str.length() - 1;
    
    while (leftIdx < rightIdx) {
        swap(str[leftIdx], str[rightIdx]);
        ++leftIdx;
        --rightIdx;
    }
}

void reverseWord(string& str, int leftIdx, int rightIdx) {
//    printf("%d -> %d\n", leftIdx, rightIdx);
    while (leftIdx < rightIdx) {
        swap(str[leftIdx], str[rightIdx]);
        ++leftIdx;
        --rightIdx;
    }
}

int main() {
    string test_str = "others with yourself compare you If";;
    printf("%s\n", test_str.c_str());
    reverseChar(test_str);
    
    size_t l = 0;
    size_t r = 0;
    while (test_str[r] != '\0') {
        if (test_str[r] == ' ') {
            reverseWord(test_str, l, r - 1);
            l = r + 1;
        }
        ++r;
    }
    reverseWord(test_str, l, r - 1);
    l = r + 1;
    
    printf("%s\n", test_str.c_str());
    return 0;
}
