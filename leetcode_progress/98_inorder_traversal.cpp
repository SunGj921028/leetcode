#include<iostream>
#include<vector>

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int > ans;
        if(root == nullptr){ return ans;}
        call_fun(root, ans);

        return ans;
    }

    void call_fun(TreeNode *root, vector<int > &ans){
        if(root != nullptr){
            call_fun(root->left, ans);
            ans.push_back(root->val);
            call_fun(root->right, ans);
        }
        return;
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
    vector<int > ans = s.inorderTraversal(root);
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}