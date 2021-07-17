//
//  main.cpp
//  HR_algo_implem_flatland-space-stations
//
//  Created by Jose Mari Syjuco on 17/7/21.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

int flatlandSpaceStations(int n, vector<int> c) {
    if (n == c.size()) return 0;
    
    int* cityMap = new int[n];
    
    for (int j = 0; j < c.size(); ++j) cityMap[c[j]] = -1;
    for (int i = 0; i < n; ++i) printf("%d ", cityMap[i]);
    
    int max_dist = 0;
    for (int i = 0; i < n; ++i) {
        if (cityMap[i] != -1) {
            for (int j = 0; j < c.size(); ++j) {
                int dist = c[j] - i;
                int val = abs(dist);
                if (cityMap[i] == 0) cityMap[i] = val;
                else if (val < cityMap[i]) cityMap[i] = val;
            }
            if (cityMap[i] > max_dist) max_dist = cityMap[i];
        }
    }
    printf("\n");
    for (int i = 0; i < n; ++i) printf("%d ", cityMap[i]);
    return max_dist;
}

int main(int argc, const char * argv[]) {
    static const int arr[] = {0, 4};
    vector<int> c (arr, arr + sizeof(arr) / sizeof(arr[0]) );
    int result = flatlandSpaceStations(5, c);
    printf("\n%d\n", result);
    return 0;
}
