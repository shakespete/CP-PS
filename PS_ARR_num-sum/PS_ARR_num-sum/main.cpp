//
//  main.cpp
//  PS_ARR_num-sum
//
//  Created by Jose Mari Syjuco on 23/10/21.
//

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> numSum(vector<int> array, int targetSum) {
    vector<vector<int>> result = {};
    sort(array.begin(), array.end());
    
    int len = (int) array.size();
    printf("%d\n", len);
    for (int i = 0; i < len - 2; ++i) {
        int a = array[i];
        int bCursor = i + 1;
        int cCursor = len - 1;
        while (bCursor < cCursor) {
            printf("CURSOR: %d %d\n", bCursor, cCursor);
            int b = array[bCursor];
            int c = array[cCursor];
            int computedSum = a + b + c;
            if (computedSum == targetSum) {
                printf("%d %d %d\n", a, b, c);
                result.push_back({a, b, c});
                ++bCursor;
                --cCursor;
            } else {
                if (computedSum < targetSum) ++bCursor;
                else --cCursor;
            }
        }
    }
    return result;
}

int main() {
    vector<int> test_1 = { -8, -6, 1, 2, 3, 5, 6, 12 };
    vector<vector<int>> res_1 = numSum(test_1, 0);
    for (int i = 0; i < res_1.size(); ++i) {
        printf("%d %d %d\n", res_1[i][0], res_1[i][1], res_1[i][2]);
    }
    return 0;
}
