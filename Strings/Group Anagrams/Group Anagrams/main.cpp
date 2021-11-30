//
//  main.cpp
//  Group Anagrams
//
//  Created by Jose Mari Syjuco on 30/11/21.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramGrps;
    
    for (auto s : strs) {
        string sortedWord = s;
        sort(sortedWord.begin(), sortedWord.end());
        
        if (anagramGrps.find(sortedWord) == anagramGrps.end()) {
            anagramGrps.insert({ sortedWord, vector<string>{ s } });
        } else {
            anagramGrps[sortedWord].push_back(s);
        }
    }
    
    vector<vector<string>> ans = {};
    for (auto grp : anagramGrps) {
        ans.push_back(grp.second);
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    vector<string> n1 = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans1 = groupAnagrams(n1);
    
    for (auto grp : ans1) {
        for (auto word : grp) {
            cout << word << " ";
        }
        cout << "\n";
    }
    
    std::cout << "FIN\n";
    return 0;
}
