//
//  main.cpp
//  Remove BST Node
//
//  Created by Jose Mari Syjuco on 22/11/21.
//

#include <iostream>

using namespace std;

class BST {
public:
    int val;
    BST *left;
    BST *right;
    BST(int x) : val(x), left(nullptr), right(nullptr) {}
    int minVal(BST* x) {
        if (!x->left) return x->val;
        else return minVal(x->left);
    }
    BST* deleteNode(BST* root, int key) {
        if (!root) return root;
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left) {
                BST* right = root->right;
                return right;
            }
            else if (!root->right) {
                BST* left = root->left;
                return left;
            }
            else {
                int min = minVal(root->right);
                root->val = min;
                root->right = deleteNode(root->right, min);
            }
        }
        return root;
    }
    void inorderTraversal(BST* root) {
        if (root) {
            inorderTraversal(root->left);
            cout << root->val << " ";
            inorderTraversal(root->right);
        }
    }
};

int main() {
    BST* root = new BST(5);
    root->left = new BST(3);
    root->left->left = new BST(2);
    root->left->right = new BST(4);
    root->right = new BST(6);
    root->right->right = new BST(7);
    root->inorderTraversal(root);
    
    cout << "\nRemove 3\n";
    root->deleteNode(root, 3);
    root->inorderTraversal(root);
    cout << "\nFIN\n";
    return 0;
}
