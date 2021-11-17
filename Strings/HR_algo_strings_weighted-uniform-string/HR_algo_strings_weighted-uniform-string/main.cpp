//
//  main.cpp
//  HR_algo_strings_weighted-uniform-string
//
//  Created by Jose Mari Syjuco on 3/9/21.
//

#include <iostream>
#include <vector>

using namespace std;

int getLetterVal(char e) {
    return e - 'a' + 1;
}

vector<string> weightedUniformStrings(string s, vector<int> queries) {
    vector<string> res;
    vector<bool> hm(10000000, false);
    
    int acc = 0;
    for (int i = 0; i < s.size(); ++i) {
        int curr = getLetterVal(s[i]);
        if (i == 0) {
            printf("%c: %d\n", s[i], curr);
            hm[curr] = true;
        } else if (getLetterVal(s[i - 1]) == curr) {
            acc += curr;
            printf("%c: %d\n", s[i], acc);
            hm[acc] = true;
        } else {
            acc = curr;
            printf("%c: %d\n", s[i], curr);
            hm[curr] = true;
        }
    }
    
    for (int i = 0; i < queries.size(); ++i) {
        if (hm[queries[i]]) res.push_back("YES");
        else res.push_back("NO");
    }
    return res;
}

int main(int argc, const char * argv[]) {
    string s = "abccdddexxxyz";
    vector<int> queries = {1, 7, 5, 4, 15};
        
    vector<string> ans = weightedUniformStrings(s, queries);
    
    return 0;
}
