//
//  main.cpp
//  HR_algo_strings_weighted-uniform-string
//
//  Created by Jose Mari Syjuco on 3/9/21.
//

#include <iostream>
#include <vector>

using namespace std;

vector<string> weightedUniformStrings(string s, vector<int> queries) {
    vector<string> res;
    
    for (int i = 0; i < s.size(); ++i) {
        char letter = s[i];
        int ascii = letter - '0';
        int val = ascii - 48;
        printf("%c %d\n", s[i], val);
        
        
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
    string s = "aaabbbbcccddd";
    vector<int> queries = {1, 7, 5, 4, 15};
        
    vector<string> ans = weightedUniformStrings(s, queries);
    
    return 0;
}
