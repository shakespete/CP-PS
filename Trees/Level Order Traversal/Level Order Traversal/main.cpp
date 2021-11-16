//
//  main.cpp
//  Level Order Traversal
//
//  Created by Jose Mari Syjuco on 16/11/21.
//

#include <queue>
#include <stdio.h>

using namespace std;

class Node {
public:
    int value;
    Node *left;
    Node *right;
    Node(int v) {
        value = v;
        left = nullptr;
        right = nullptr;
    }
};

void levelOrder(Node * root) {
        queue<Node *> q;
        q.push(root);
        
        while (!q.empty()) {
            Node *current = q.front();
            printf("%d ", current->value);
            q.pop();
            
            Node *left = current->left;
            Node *right = current->right;
            
            if (left) q.push(left);
            if (right) q.push(right);
        }
    }

int main() {
    Node *root = new Node(1);
    root->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(6);
    root->right->right->left = new Node(3);
    root->right->right->left->right = new Node(4);
    
    levelOrder(root);
    printf("\nFIN\n");
    return 0;
}

//  1
//   \
//    2
//     \
//      5
//    /   \
//   3     6
//    \
//     4
