//
//  main.cpp
//  Iterative Descending Order
//
//  Created by Jose Mari Syjuco on 25/11/21.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int e) {
        val = e;
        left = nullptr;
        right = nullptr;
    }
};

void descWalkRecursive(Node *x) {
    if (x) {
        descWalkRecursive(x->right);
        cout << x->val << " ";
        descWalkRecursive(x->left);
    }
}

void descWalkIterative(Node* root) {
    stack<Node*> st;
    Node* curr = root;
    
    while (curr || !st.empty()) {
        
        while (curr) {
            st.push(curr);
            curr = curr->right;
        }
        
        curr = st.top();
        cout << curr->val << " ";
        curr = curr->left;
        
        st.pop();
    }
}

int main(int argc, const char * argv[]) {
    Node* root = new Node(3);
    root->left = new Node(2);
    root->left->right = new Node(2);
    root->left->left = new Node(1);
    
    root->right = new Node(3);
    root->right->right = new Node(5);
    root->right->right->left = new Node(4);
    root->right->right->right = new Node(7);
    
    descWalkRecursive(root);
    cout << "\n";
    descWalkIterative(root);
    std::cout << "\nFIN\n";
    return 0;
}

//      3
//    /   \
//   2     3
//  / \     \
// 1   2     5
//          / \
//         4   7
