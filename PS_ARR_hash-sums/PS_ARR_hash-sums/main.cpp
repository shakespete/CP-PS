//
//  main.cpp
//  PS_ARR_hash-sums
//
//  Created by Jose Mari Syjuco on 27/10/21.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string getWinner(vector<vector<string>> competitions, vector<int> results) {
    int highestScore = 0;
    string topTeam = "";
    
    unordered_map<string, int> teams;
    
    for (int i = 0; i < competitions.size(); ++i) {
        vector<string> competingTeams = competitions[i];
        
        string winningTeam = results[i] == 1 ? competingTeams[0] : competingTeams[1];
        auto teamToGetPts = teams.find(winningTeam);
        
        if (teamToGetPts != teams.end()) {
            int totalPts = teamToGetPts->second + 3;
            teamToGetPts->second = totalPts;
            
            if (totalPts > highestScore) {
                highestScore = totalPts;
                topTeam = teamToGetPts->first;
            }
        } else {
            teams.insert({ winningTeam, 3 });
            if (!highestScore) {
                highestScore = 3;
                topTeam = winningTeam;
            }
        }
    }
    return topTeam;
}

int main() {
    vector<vector<string>> competitions = { {"HTML", "C#"}, {"C#", "Python"}, {"Python", "HTML"} };
    vector<int> results = { 0, 0, 1 };
    string winner = getWinner(competitions, results);
    printf("%s\n", winner.c_str());
    printf("\nFIN\n");
    return 0;
}
