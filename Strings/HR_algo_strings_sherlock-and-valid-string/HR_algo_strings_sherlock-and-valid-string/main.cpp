//
//  main.cpp
//  HR_algo_strings_sherlock-and-valid-string
//
//  Created by Jose Mari Syjuco on 22/10/21.
//

#include <stdio.h>
#include <string>

using namespace std;

string isValid(string s) {
    if (s.length() == 1) return "YES";
    int* charCounters = new int[26]{0};
    int top = 0;
    int topCounter = 0;
    
    for (int i = 0; i < s.length(); ++i) {
        int charIdx = s[i] - 'a';
        charCounters[charIdx]++;
    }
    
    int bottom = 0;
    for (int i = 0; i < 26; ++i) {
        int count = charCounters[i];
        if(count) {
            if (count > top) {
                top = count;
                topCounter = 1;
            } else if (count == top) {
                topCounter++;
            }
            
            if (bottom == 0 || count < bottom) bottom = count;
        }
    }
    printf("H: %d L: %d\n", top, bottom);
    printf("%d\n", topCounter);
    
    if (topCounter == 1 && top - 1 == bottom) return "YES";
    return "NO";
}

int main() {
//    string result = isValid("aabbccddeefghi");
//    printf("ANS: %s\n", result.c_str());
//    string result1 = isValid("abcdefghhgfedecba");
//    printf("ANS: %s\n", result1.c_str());
//    string result2 = isValid("aaaabbcc");
//    printf("ANS: %s\n", result2.c_str());
    string result2 = isValid("aabbc");
    printf("ANS: %s\n", result2.c_str());
    return 0;
}
