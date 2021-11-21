//
//  main.cpp
//  Reconstruct Binary Tree
//
//  Created by Jose Mari Syjuco on 21/11/21.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinaryTree {
public:
    TreeNode* reconstruct(int& rootIdx, int leftIdx, int rightIdx, vector<int>& inorder, vector<int>& postorder) {
        if (rootIdx < 0 || leftIdx > rightIdx) return nullptr;
        
        // 3 -> 20 -> 7 -> 15 -> 9
        int rootVal = postorder[rootIdx];
        
        // Search for root value in inorder traversal array
        int currIdx = 0;
        while (inorder[currIdx] != rootVal) currIdx++;
        
        rootIdx--; // Update to next root index
        
        /**
              root
               |
            [ 9, 3, 15, 20, 7 ]
            left     right---->
         */
        
        TreeNode *right = reconstruct(rootIdx, currIdx + 1, rightIdx, inorder, postorder);
        TreeNode *left = reconstruct(rootIdx, leftIdx, currIdx - 1, inorder, postorder);
        TreeNode *root = new TreeNode(rootVal, left, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int N = (int)postorder.size();
        int rootIdx = N - 1;
        return reconstruct(rootIdx, 0, N - 1, inorder, postorder);
    }
};

int main() {
    vector<int> inorder = { 9, 3, 15, 20, 7 };      // left root right
    vector<int> postorder = { 9, 15, 7, 20, 3 };    // left right root
    
    BinaryTree* bt = new BinaryTree();
    TreeNode* root = bt->buildTree(inorder, postorder);
    printf("%d\n", root->val);
    printf("%d %d\n", root->left->val, root->right->val);
    printf("%d %d\n", root->right->left->val, root->right->right->val);
    printf("FIN\n");
    return 0;
}



//     3
//    / \
//   9   20
//      /  \
//     15   7
