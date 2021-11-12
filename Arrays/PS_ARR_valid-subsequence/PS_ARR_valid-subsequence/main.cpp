//
//  main.cpp
//  PS_ARR_valid-subsequence
//
//  Created by Jose Mari Syjuco on 26/10/21.
//

#include <stdio.h>
#include <vector>

using namespace std;

bool validSub(vector<int> array, vector<int> sequence) {
    int cursor = 0;
    
    for (int element : array) {
        if (element == sequence[cursor]) ++cursor;
    }
    
    if (cursor == sequence.size()) return true;
    return false;
}

int main(int argc, const char * argv[]) {
    vector<int> arr = { 5, 1, 22, 25, 6, -1, 8, 10 };
    vector<int> seq = { 1, 6, -1, 10 };
    
    printf(validSub(arr, seq) ? "true" : "false");
    printf("\n");
    return 0;
}
