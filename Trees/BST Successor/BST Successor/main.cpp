//
//  main.cpp
//  BST Successor
//
//  Created by Jose Mari Syjuco on 2/12/21.
//

#include <iostream>

class BST {
public:
    int val;
    BST* left;
    BST* right;
    BST(int e) {
        val = e;
        left = nullptr;
        right = nullptr;
    }
    // Time: O(h) | Space(1)
    BST* inorderSuccessor(BST* root, BST* target) {
        BST* current = root;
        BST* successor = nullptr;
        
        while (current) {
            if (current->val > target->val) {
                successor = current;
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return successor;
    }
};

int main(int argc, const char * argv[]) {
    BST* root = new BST(5);
    root->right = new BST(6);
    root->left =new BST(3);
    root->left->right = new BST(4);
    root->left->left = new BST(2);
    root->left->left->left = new BST(1);
    
    BST* s1 = root->inorderSuccessor(root, root->right);
    int ans1 = s1 ? s1->val : -1;
    std::cout << ans1 << "\n";
    
    BST* s2 = root->inorderSuccessor(root, root->left->right);
    std::cout << s2->val << "\n";
    
    std::cout << "FIN\n";
    return 0;
}
