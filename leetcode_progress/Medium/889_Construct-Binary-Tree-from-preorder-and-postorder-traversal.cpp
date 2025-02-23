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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preIdx = 0, postIdx = 0;
        return constructTree(preIdx, postIdx, preorder, postorder);
    }
private:
    TreeNode* constructTree(int& preIndex, int& postIndex, vector<int>& preorder, vector<int>& postorder){
        // Create a new node with the value at the current preorder index
        TreeNode* root = new TreeNode(preorder[preIndex++]);


        //? Postorder traversal is left -> right -> root(so, the last element is the root)
        //! Recursively construct the left subtree if the root is not the last of its subtree
        if(root->val != postorder[postIndex]){
            root->left = constructTree(preIndex, postIndex, preorder, postorder);
        }

        //! Recursively construct the right subtree if the root is still not the last of its subtree
        if(root->val != postorder[postIndex]){
            root->right = constructTree(preIndex, postIndex, preorder, postorder);
        }

        postIndex++;
        return root;
    }
};

int main(){
    Solution sol;
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};
    TreeNode* root = sol.constructFromPrePost(preorder, postorder);
    return 0;
}