//
//  main.cpp
//  HR_algo_recursion_crossword-puzzle
//
//  Created by Jose Mari Syjuco on 21/7/21.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

/*
 * Complete the 'crosswordPuzzle' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY crossword
 *  2. STRING words
 */

void traverse(int x, int y, vector<string> &grid) {
    if (grid[y][x] == '-') {
        grid[y][x] = 'a';
    }
}

vector<string> crosswordPuzzle(vector<string> crossword, string words) {
    char** strArray = new char*[10];
    int arrIndx = 0;
    int len = 0;
    for (int i = 0; i < words.length(); ++i) {
        if (words[i] == ';') {
            len = 0;
            arrIndx++;
        }
        else {
            
        }
    }
    
    
    int y = 0;
    for (auto& word: crossword) {
        int x = 0;
        for (auto& letter: word) {
            printf("%c ", letter);
            traverse(x, y, crossword);
            x++;
        }
        y++;
        printf("\n");
    }
    return crossword;
}

int main(int argc, const char * argv[]) {
    vector<string> crossword(10);
    
    crossword[0] = "+-++++++++";
    crossword[1] = "+-++++++++";
    crossword[2] = "+-++++++++";
    crossword[3] = "+-----++++";
    crossword[4] = "+-+++-++++";
    crossword[5] = "+-+++-++++";
    crossword[6] = "+++++-++++";
    crossword[7] = "++------++";
    crossword[8] = "+++++-++++";
    crossword[9] = "+++++-++++";
    
    string words = "LONDON;DELHI;ICELAND;ANKARA";
    
    vector<string> ans = crosswordPuzzle(crossword, words);
    
    printf("\n");
    for (auto& word: ans){
        for (auto& letter: word) {
            printf("%c ", letter);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
