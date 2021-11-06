//
//  main.cpp
//  PS_DYP_max-no-neighbor
//
//  Created by Jose Mari Syjuco on 6/11/21.
//

#include <algorithm>
#include <vector>
using namespace std;

// Time: O(n) Space: O(n)
int maxNoNeighbor(vector<int> array) {
    int N = (int)array.size();
    if (array.size() == 0) return 0;
    if (array.size() == 1) return array[0];
    
    vector<int> maxValues(N, -1);
    maxValues[0] = array[0];
    maxValues[1] = max(array[0], array[1]);
    
    for (int i = 2; i < N; ++i) {
        int comboA = array[i] + maxValues[i - 2];
        int comboB = maxValues[i - 1];
        maxValues[i] = max(comboA, comboB);
    }
    return maxValues[N - 1];
}

int main() {
    vector<int> arr{75, 105, 120, 75, 90, 135};
    int ans = maxNoNeighbor(arr);
    printf("%d\n", ans);
    printf("FIN\n");
    return 0;
}
