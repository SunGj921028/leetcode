#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isSymmetric(root->left,root->right);
    }
    bool isSymmetric(TreeNode* left,TreeNode* right){
        if(left == NULL && right == NULL) return true;
        if(left == NULL || right == NULL) return false;
        if(left->val != right->val) return false;
        return isSymmetric(left->left,right->right) && isSymmetric(left->right,right->left);
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(4);
    TreeNode* node6 = new TreeNode(3);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right= node4;
    node2->left = node5;
    node2->right= node6;
    Solution s;
    cout<<s.isSymmetric(root)<<endl;
    return 0;
}