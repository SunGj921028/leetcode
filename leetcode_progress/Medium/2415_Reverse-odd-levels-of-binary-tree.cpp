#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        traverseDFS(root->left, root->right, 0); // Start from level 0(root)
        return root;
    }
private:
    void traverseDFS(TreeNode * leftChild, TreeNode * rightChild, int level){
        // Level is to check current level is odd or even
        // If is odd, then swap the left and right child
        
        // Base case
        if(leftChild == nullptr || rightChild == nullptr){
            return;
        }

        if(level % 2 == 0){
            int tmp = leftChild->val;
            leftChild->val = rightChild->val;
            rightChild->val = tmp;
        }

        traverseDFS(leftChild->left, rightChild->right, level + 1); //! Mirror structure
        traverseDFS(leftChild->right, rightChild->left, level + 1);
    }
};

int main(){
    Solution solution;

    // Create the binary tree
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(13);
    root->right->left = new TreeNode(21);
    root->right->right = new TreeNode(34);

    // Call the solution
    TreeNode* result = solution.reverseOddLevels(root);
}
