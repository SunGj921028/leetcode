#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

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
    //! 動態規劃思路
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr){ return result;}

        // 后序遍历结果特点：先是左子树，接着是右子树，最后是根节点的值
        vector<int > left = postorderTraversal(root->left);
        vector<int > right = postorderTraversal(root->right);
        result.insert(result.end(), left.begin(), left.end());
        result.insert(result.end(), right.begin(), right.end());
        result.push_back(root->val);
        return result;
    }
};

int main(){
    Solution s;
    TreeNode *root1 = nullptr;
    TreeNode *root2 = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, nullptr, new TreeNode(6)));
    TreeNode *root3 = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));

    vector<int> result1 = s.postorderTraversal(root1);
    vector<int> result2 = s.postorderTraversal(root2);
    vector<int> result3 = s.postorderTraversal(root3);

    cout << "Postorder Traversal of root1: ";
    for (int val : result1) cout << val << " ";
    cout << endl;

    cout << "Postorder Traversal of root2: ";
    for (int val : result2) cout << val << " ";
    cout << endl;

    cout << "Postorder Traversal of root3: ";
    for (int val : result3) cout << val << " ";
    cout << endl;
    return 0;
}