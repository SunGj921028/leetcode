#include<iostream>

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
        TreeNode* invertTree(TreeNode* root){
            if(root == nullptr){ return nullptr;}
            TreeNode* left = invertTree(root->left);
            TreeNode* right = invertTree(root->right);
            root->left = right;
            root->right = left;
            return root;
        }
};

class Solution2 {
    public:
        TreeNode* invertTree(TreeNode* root){
            traverse(root);
            return root;
        }

        TreeNode* traverse(TreeNode* root){
            if(root == nullptr){ return nullptr;}
            // swap left and right
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;

            traverse(root->left);
            traverse(root->right);
            return root;
        }
};