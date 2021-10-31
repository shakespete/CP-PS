//
//  main.cpp
//  PS_STR_gen-doc
//
//  Created by Jose Mari Syjuco on 31/10/21.
//

#include <stdio.h>
#include <unordered_map>
#include <string>

using namespace std;

// Time: O(m + n) Space: O(u)
bool genDoc(string characters, string document) {
    unordered_map<char, int> charMap;
    
    for (auto c : characters) {
        if (charMap.find(c) != charMap.end()) charMap[c]++;
        else charMap[c] = 1;
    }
    
    for (auto l : document) {
        if (charMap.find(l) == charMap.end() || charMap[l] == 0) return 0;
        charMap[l]--;
    }
    return 1;
}


int main() {
    
    auto x = "aheaollabbhb";
    auto y = "hello";
    int ans = genDoc(x, y);
    printf("%d\n", ans);
    return 0;
}
