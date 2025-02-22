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


//! Iterative Approach with Stack (Single Pass)
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> nodeStack;
        int idx = 0;

        while(idx < traversal.size()){
            //? Count the number of dashes
            int depth = 0;
            while(idx < traversal.size() && traversal[idx] == '-') {
                depth++;
                idx++;
            }

            int val = 0;
            while(idx < traversal.size() && isdigit(traversal[idx])){ // It might be 1-456--6
                val = val * 10 + (traversal[idx] - '0');
                idx++;
            }

            TreeNode* node = new TreeNode(val);

            while(nodeStack.size() > depth){ //! Find the parent node
                nodeStack.pop();
            }

            if(!nodeStack.empty()){
                if(nodeStack.top()->left == nullptr){ //! single child
                    nodeStack.top()->left = node;
                }else{
                    nodeStack.top()->right = node; //! Have sibilings
                }
            }

            nodeStack.push(node);
        }

        while(nodeStack.size() > 1){
            nodeStack.pop();
        }

        return nodeStack.top();
    }
};

int main(){
    Solution* obj = new Solution();
    cout << obj->recoverFromPreorder("1-2--3--4-5--6--7") << endl;
    cout << obj->recoverFromPreorder("1-2--3---4-5--6---7") << endl;
    cout << obj->recoverFromPreorder("1-401--349---90--88") << endl;
    return 0;
}