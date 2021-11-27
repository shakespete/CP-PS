//
//  main.cpp
//  Product Array
//
//  Created by Jose Mari Syjuco on 27/11/21.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> productsExceptCurrIdx(vector<int> array) {
    vector<int> products = { 1 };
    // Products on left hand side
    for (int i = 1; i < array.size(); ++i) {
        int currProduct = array[i - 1] * products[i - 1];
        products.push_back(currProduct);
    }
    
    // Products on right hand side
    int runningRightProduct = 1;
    for (int j = (int)array.size() - 2; j >= 0; --j) {
        runningRightProduct *= array[j + 1];
        products[j] *= runningRightProduct;
    }
    return products;
}

int main(int argc, const char * argv[]) {
    vector<int> n1 = {1,2,3,4};
    vector<int> ans1 = productsExceptCurrIdx(n1);
    for (auto i : ans1) cout << i << " ";
    cout << "\n";
    
    vector<int> n2 = {-1,1,0,-3,3};
    vector<int> ans2 = productsExceptCurrIdx(n2);
    for (auto i : ans2) cout << i << " ";
    cout << "\n";
    
    std::cout << "FIN\n";
    return 0;
}
