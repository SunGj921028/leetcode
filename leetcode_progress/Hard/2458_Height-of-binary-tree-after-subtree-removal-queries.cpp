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

//! DFS

class Solution {
public:
    unordered_map<int, int> mp1, mp2, sz;// mp1:節點值到ID, mp2:節點ID到高度, sz:子樹大小
    int id = 0;// 為每個節點分配唯一ID
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> ans;// 存放每個查詢結果
        dfs(root, 0); // 深度優先搜索計算每個節點的高度與子樹大小

        vector<int> left(id), right(id);// 儲存left與right的最大值

        // 填入left陣列
        for(int i = 0; i < left.size(); i++) {
            left[i] = mp2[i];
            if(i) left[i] = max(left[i - 1], left[i]);
        }
        
        // 填入right陣列
        for(int i = right.size() - 1; i >= 0; i--) {
            right[i] = mp2[i];
            if(i + 1 < right.size()) right[i] = max(right[i], right[i + 1]);
        }
        
        // 處理每個查詢
        for(int i = 0; i < queries.size(); i++) {
            int nodeid = mp1[queries[i]]; // 查詢節點的ID
            int l = nodeid, r = l + sz[nodeid] - 1; // 移除區間 [l:r]
            int h = 0;
            if(l > 0) h = max(h, left[l - 1]); // 左側最大值
            if(r + 1 < right.size()) h = max(h, right[r + 1]); // 右側最大值
            ans.push_back(h);
        }
        return ans;
    }

    int dfs(TreeNode* root, int h) { //? return the size of the subtree, 計算每個節點的子樹大小與高度
        if(root == NULL) {
            return 0;
        }
        mp1[root -> val] = id; // 記錄節點值對應的ID
        mp2[id] = h; // 記錄ID的高度
        id++;
        int lz = dfs(root -> left, h + 1); // 遞迴左子樹
        int rz = dfs(root -> right, h + 1); // 遞迴右子樹
        sz[mp1[root -> val]] = (1 + lz + rz); // 子樹大小計算
        return 1 + lz + rz;
    }
};

int main(){}