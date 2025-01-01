#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if(root == nullptr){ return 0;}
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }

        int max(int a, int b){
            return a > b ? a : b;
        }
};

int main(){
    Solution sol;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << sol.maxDepth(root) << endl;
    return 0;
}
