#include <stdio.h>
#include <string>

#define MAX_N 205
int grid[205][205];

void move(int curr_row, int curr_col, int steps, char** stepsArr) {
    
}

void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end) {
    // Print the distance along with the sequence of moves.
    printf("%d\n", n);
    printf("S: %d %d\n", i_start, j_start);
    printf("E: %d %d\n", i_end, j_end);
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            grid[i][j] = 0;
    
    grid[i_start][j_start] = -1;
    grid[i_end][j_end] = -1;
            
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
}

int main() {
    string test_str = "others with yourself compare you If";;
    printf("%s\n", test_str.c_str());
    reverseWords(test_str);
    printf("%s\n", test_str.c_str());
    return 0;
}
