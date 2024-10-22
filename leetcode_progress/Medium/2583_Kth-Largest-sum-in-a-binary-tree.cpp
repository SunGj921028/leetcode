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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> res;      // To store sum of each level
        queue<TreeNode*> q;         // Queue for level-order traversal (BFS)
        q.push(root);               // Start BFS from the root node
        while(!q.empty()){
            int n = q.size();       // Number of nodes at the current level
            long long sum = 0;      // Sum of node values at the current level

            // Process all nodes at the current level
            while(n--){
                TreeNode* node = q.front(); q.pop();   // Get the front node from the queue
                sum += node->val;                       // Add the value of the current node to the sum

                // Push left and right children of the node to the queue (if they exist)
                if(node->left){ q.push(node->left);}
                if(node->right){ q.push(node->right);}
            }
            res.push_back(sum);
        }

        if(k > res.size()){ return -1;}

        // Sort the sum of each level in descending order
        sort(res.begin(), res.end(), greater<long long>());

        return res[k - 1];
    }
};

int main(){
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    cout << sol.kthLargestLevelSum(root, 3) << endl;
    return 0;
}