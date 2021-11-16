//
//  main.cpp
//  PS_BIT_branch-sums
//
//  Created by Jose Mari Syjuco on 23/10/21.
//

#include <stdio.h>
#include <vector>

using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;
    
    BinaryTree(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class TestBinaryTree : public BinaryTree {
public:
    TestBinaryTree(int value) : BinaryTree(value){};
    
    BinaryTree *insert(vector<int> values, int i = 0) {
        if (i >= values.size())
            return nullptr;
        vector<BinaryTree *> queue = {this};
        while (queue.size() > 0) {
            BinaryTree *current = queue[0];
            queue.erase(queue.begin());
            if (current->left == nullptr) {
                current->left = new BinaryTree(values[i]);
                break;
            }
            queue.push_back(current->left);
            if (current->right == nullptr) {
                current->right = new BinaryTree(values[i]);
                break;
            }
            queue.push_back(current->right);
        }
        insert(values, i + 1);
        return this;
    }
};


void traverse(BinaryTree* node, int sum, vector<int> &res) {
    if (node->left) traverse(node->left, sum + node->left->value, res);
    if (node->right) traverse(node->right, sum + node->right->value, res);
    if (!node->left && !node->right) res.push_back(sum);
}

vector<int> branchSums(BinaryTree *root) {
    vector<int> result;
    traverse(root, root->value, result);
    return result;
}


int main() {
    TestBinaryTree *tree = new TestBinaryTree(1);
    tree->insert({2, 3, 4, 5, 6, 7, 8, 9, 10});
    vector<int> ans = branchSums(tree);
    for (int i : ans) printf("%d ", i);
    printf("\nFIN\n");
    return 0;
}
