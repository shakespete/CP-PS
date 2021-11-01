//
//  main.cpp
//  PS_ARR_min-dist
//
//  Created by Jose Mari Syjuco on 1/11/21.
//

#include <vector>

using namespace std;

int getAbsDiff(int x, int y) {
    if (x > y) return x - y;
    if (y > x) return y - x;
    return x - y;
}

// Time: O(mlog(m)) + O(nlog(n)) Space: O(1)
vector<int> minDistance(vector<int> arrayOne, vector<int> arrayTwo) {
    vector<int> ans = { 0, 0 };
    sort(arrayOne.begin(), arrayOne.end());
    sort(arrayTwo.begin(), arrayTwo.end());
    
    int cursorOne = 0;
    int cursorTwo = 0;
    int smallestDiff = INT_MAX;
    while (cursorOne < arrayOne.size() && cursorTwo < arrayTwo.size()) {
        int val1 = arrayOne[cursorOne];
        int val2 = arrayTwo[cursorTwo];
        int diff = getAbsDiff(val1, val2);
        
        if (diff < smallestDiff) {
            ans[0] = val1;
            ans[1] = val2;
            smallestDiff = diff;
        }
        if (diff == 0) break;
        if (val1 < val2) cursorOne++;
        if (val2 < val1) cursorTwo++;
    }
    return ans;
}

int main() {
    vector<int> res = minDistance({-1, 5, 10, 20, 28, 3}, {26, 134, 135, 15, 17});
    printf("%d %d\n", res[0], res[1]);
    return 0;
}
