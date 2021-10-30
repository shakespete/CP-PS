//
//  main.cpp
//  PS_RCR_nth-fibo
//
//  Created by Jose Mari Syjuco on 30/10/21.
//

#include <stdio.h>
#include <unordered_map>

using namespace std;

int generateSequence(int n, unordered_map<int, int> &fibMap) {
    auto fibVal = fibMap.find(n);
    if (fibVal != fibMap.end()) return fibMap[n];
    else {
        int n1 = generateSequence(n - 1, fibMap);
        int n2 = generateSequence(n - 2, fibMap);
        int newFibVal = n1 + n2 ;
        fibMap.insert({ n, newFibVal });
        return fibMap[n];
    }
}
// Time: O(n) Space: O(n)
int getNthFib(int n) {
    unordered_map<int, int> fibMap = { { 1, 0 }, { 2, 1 } };
    return generateSequence(n, fibMap);
}

// Time: O(n) Space: O(1)
int getNthFibo(int n) {
    int previousTwo[] = { 0, 1 };
    int cursor = 3;
    while (cursor <= n) {
        int newFib = previousTwo[0] + previousTwo[1];
        cursor++;
        previousTwo[0] = previousTwo[1];
        previousTwo[1] = newFib;
    }
    return n == 1 ? previousTwo[0] : previousTwo[1];
}


int main() {
    //f: 0 1 1 2 3 5 8 13 ...
    //n: 1 2 3 4 5 6 7 8
    
    int rec = getNthFib(8);
    printf("n=6: %d\n", rec);
    
    int itr = getNthFibo(8);
    printf("n=6: %d\n", itr);
    return 0;
}
