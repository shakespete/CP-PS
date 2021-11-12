//
//  main.cpp
//  PS_ARR_waiting-sum
//
//  Created by Jose Mari Syjuco on 28/10/21.
//

#include <stdio.h>

#include<vector>
#include<algorithm>

using namespace std;

// Space: O(nlog(n)) Time: O(1)
int waitingSum(vector<int> queries) {
    // O(nlog(n))
    sort(queries.begin(), queries.end());
    
    // O(n)
    int totalWaitingTime = 0;
    int durationSoFar = 0;
    for (int i = 0; i < queries.size(); ++i) {
        totalWaitingTime += durationSoFar;
        durationSoFar += queries[i];
    }
    
    return totalWaitingTime;
}

int main() {
    vector<int> queries = { 3, 2, 1, 2, 6 };
    int res = waitingSum(queries);
    printf("%d", res);
    printf("\nFIN\n");
    return 0;
}
