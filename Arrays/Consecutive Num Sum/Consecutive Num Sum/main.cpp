//
//  main.cpp
//  Consecutive Num Sum
//
//  Created by Jose Mari Syjuco on 30/12/21.
//

#include <iostream>
#include <deque>

using namespace std;

class MonotonicQueue {
public:
    deque<int> mq;
    int sum;
    int target;
    MonotonicQueue(int t) {
        sum = 0;
        target = t;
    }
    void insert(int e) {
        while (sum + e > target) {
            sum -= mq.front();
            mq.pop_front();
        }
        mq.push_back(e);
        sum += e;
    }
};

int consecutiveNumbersSum(int n) {
    if (n <= 2) return 1;
    
    MonotonicQueue* q = new MonotonicQueue(n);
    int max = n / 2 + 1;
    int ans = 1;
    
    for (int i = 1; i <= max; ++i) {
        q->insert(i);
        if (q->sum == n) ans++;
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    cout << consecutiveNumbersSum(5) << "\n";
    cout << consecutiveNumbersSum(9) << "\n";
    cout << "FIN\n";
    return 0;
}
