//
//  main.cpp
//  Knight Moves
//
//  Created by Jose Mari Syjuco on 24/2/2022.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int minKnightMoves(int x, int y) {
    vector<pair<int, int>> directions{ {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1} };
    // min val is -300, max is 300, so in total our visited space is a 600x600 grid
    // we just use 610 for assurance that we do not access invalid index
    int visited[610][610] = {};
    
    queue<vector<int>> moves;
    int ans = 0;
    
    moves.push(vector<int>{ 0, 0 }); // x, y, move_count
    visited[303][303] = 1; // Mark (0, 0) as visited
    while (!moves.empty()) { // BFS
        int levelSize = (int)moves.size();
        
        while (levelSize > 0) {
            vector<int> nextMove = moves.front();
            moves.pop();
            
            int currX = nextMove[0];
            int currY = nextMove[1];
            
            if (currX == x && currY == y) return ans;
            
            // Add all 8 possible moves from current position
            for (auto& dir : directions) {
                int i = currX + dir.first;
                int j = currY + dir.second;
                
                // Need to add 303 because we adjust x and y axis 303 units
                if (visited[i + 303][j + 303] == 0) {
                    visited[i + 303][j + 303] = 1;
                    moves.push(vector<int>{ i, j });
                }
            }
            levelSize--;
        }
        ans++;
        
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    cout << minKnightMoves(2, 1) << "\n";
    cout << minKnightMoves(5, 5) << "\n";
    cout << minKnightMoves(2, 112) << "\n";
    cout << minKnightMoves(0, -300) << "\n";
    
    std::cout << "FIN\n";
    return 0;
}
