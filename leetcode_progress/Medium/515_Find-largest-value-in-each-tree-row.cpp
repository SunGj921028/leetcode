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
    vector<int> maxValues;

    void dfs(TreeNode * root, int level){
        if(root == nullptr){ return;}
        if(maxValues.size() - 1 < level){ // Except root level = 0
            maxValues.push_back(root->val);
        } else {
            maxValues[level] = max(maxValues[level], root->val);
        }
        if(root->left != nullptr){
            dfs(root->left, level + 1);
        }
        if(root->right != nullptr){
            dfs(root->right, level + 1);
        }
        return;
    }

    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr){ return maxValues;}
        maxValues.push_back(root->val);
        int level = 0;
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
        return maxValues;
    }
};

int main(){
    Solution solution;

    // Create the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    // Call the solution
    vector<int> result = solution.largestValues(root);
    for(auto val : result){
        cout << val << " ";
    }
    cout << endl;
}