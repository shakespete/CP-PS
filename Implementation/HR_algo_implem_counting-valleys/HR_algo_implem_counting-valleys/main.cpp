//
//  main.cpp
//  HR_algo_implem_counting-valleys
//
//  Created by Jose Mari Syjuco on 11/2/21.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>

using namespace std;

int countingValleys(int steps, string path) {
    int valleyCount = 0;
    int seaLevel = true;
    int altitude = 0;
    for (int i = 0; i < steps; ++i) {
        if (path[i] == 'U') {
            altitude += 1;
            if (altitude >= 0) seaLevel = true;
        } else {
            altitude -= 1;
            if (altitude < 0) {
                if (seaLevel) valleyCount++;
                seaLevel = false;
            }
        }
    }
    return valleyCount;
}

int main() {
    int a = countingValleys(8, "UDDDUDUU");
    printf("%d\n", a);
    return 0;
}
