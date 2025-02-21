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

class FindElements {
public:
    vector<int> treeElements;

    void recover(TreeNode* root){
        if(root->left != nullptr){
            root->left->val = 2 * root->val + 1;
            treeElements.push_back(root->left->val);
            recover(root->left);
        }
        if(root->right != nullptr){
            root->right->val = 2 * root->val + 2;
            treeElements.push_back(root->right->val);
            recover(root->right);
        }
        return;
    }

    FindElements(TreeNode* root) {
        root->val = 0;
        treeElements.push_back(0);
        recover(root);
    }
    
    bool find(int target) {
        for(int element : treeElements){
            if(element == target){
                return true;
            }
        }
        return false;
    }
};

int main(){
    TreeNode* root = new TreeNode(-1);
    root->left = new TreeNode(-1);
    root->right = new TreeNode(-1);
    root->left->left = new TreeNode(-1);
    root->left->right = new TreeNode(-1);
    FindElements* obj = new FindElements(root);
    cout << obj->find(1) << endl;
    cout << obj->find(3) << endl;
    cout << obj->find(5) << endl;
    return 0;
}