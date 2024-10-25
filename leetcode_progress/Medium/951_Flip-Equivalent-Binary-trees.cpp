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

//! Recursive solution
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return check(root1, root2);
    }

private:
    bool check(TreeNode* node1, TreeNode* node2){
        if(!node1 && !node2){ return true;} // Both null will be equivalent
        if(!node1 || !node2 || (node1 -> val != node2 -> val)){ return false;}

        return ((check(node1->left, node2->left) || check(node1->left, node2->right)) && 
                (check(node1->right, node2->right) || check(node1->right, node2->left)));
    }
};

int main(){}