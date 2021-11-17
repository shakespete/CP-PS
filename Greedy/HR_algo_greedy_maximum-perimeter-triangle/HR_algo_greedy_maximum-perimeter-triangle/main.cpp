//
//  main.cpp
//  HR_algo_greedy_maximum-perimeter-triangle
//
//  Created by Jose Mari Syjuco on 12/10/21.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int getP(int a, int b, int c) {
    if (a == b && b == c) return 1;
    if (a + b > c && a + c > b && b + c > a) return a + b + c;
    return -1;
}

vector<int> maximumPerimeterTriangle(vector<int> sticks) {
    vector<int> ans;
    sort(sticks.begin(), sticks.end(), greater<int>());
    int greatestP = -1;
    for (int i = 0; i < sticks.size() - 2; ++i) {
        int p = getP(sticks[i], sticks[i + 1], sticks[i + 2]);
        printf("%d\n", p);
        if (p > greatestP) {
            greatestP = p;
            ans.push_back(sticks[i + 2]);
            ans.push_back(sticks[i + 1]);
            ans.push_back(sticks[i]);
            return ans;
        };
    };
    if (greatestP == -1) ans.push_back(-1);
    return ans;
}

int main(int argc, const char * argv[]) {
//    vector<int> sticks = { 1, 2, 3, 4, 5, 10 };
//    vector<int> sticks = { 1, 1, 1, 3, 3 };
//    vector<int> sticks = { 1, 2, 3 };
//    vector<int> sticks = { 1, 1, 1, 2, 3, 5 };
    vector<int> sticks = { 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000};
    vector<int> res = maximumPerimeterTriangle(sticks);
    for (auto x : res) printf("%d ", x);
    printf("\n");
    return 0;
}
