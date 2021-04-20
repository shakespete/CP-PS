//
//  main.cpp
//  HR_algo_warmup_diagonal-difference
//
//  Created by Jose Mari Syjuco on 20/4/21.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

typedef vector<int> Vector;
typedef vector<Vector> DoubleVector;

/*
 * Complete the 'diagonalDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int diagonalDifference(vector<vector<int>> arr) {
    int l = 0;
    int r = 0;
    int iter = 0;
    for (DoubleVector::const_iterator row = arr.begin(); row != arr.end(); ++row) {
        Vector::const_iterator col = row->begin() + iter;
        Vector::const_iterator inv = row->end() - iter - 1;
//        printf("%d %d", *col, *inv);
        l += *col;
        r += *inv;
        ++iter;
        
//        for (DoubleVector::const_iterator row = arr.begin(); row != arr.end(); ++row) {
//            for (Vector::const_iterator col = row->begin(); col != row->end(); ++col) {
//
//            }
//        }
//        printf("\n");
    }
    int ans = l - r;
    return ans > 0 ? ans : -ans;
}

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> vec{ { 11, 2, 4 },
                             { 4, 5, 6 },
                             { 10, 8, -12 } };
    
    printf("%d\n", diagonalDifference(vec));
    return 0;
}
