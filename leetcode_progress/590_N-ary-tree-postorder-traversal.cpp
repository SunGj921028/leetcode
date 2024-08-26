#include<bits/stdc++.h>

using namespace std;

/*
Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int > res;
    void traverse(Node* root){
        if(root == nullptr){ return;}

        // 前序遍历位置
        for (Node* child : root->children) {
            traverse(child);
        }
        // 后序遍历位置
        res.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        if(root == nullptr){ return res;}

        traverse(root);
        return res;
    }
};

int main(){
    // Test case 1
    Node* root1 = new Node(1);
    root1->children.push_back(new Node(3));
    root1->children.push_back(new Node(2));
    root1->children.push_back(new Node(4));
    root1->children[0]->children.push_back(new Node(5));
    root1->children[0]->children.push_back(new Node(6));

    Solution solution;
    vector<int> result1 = solution.postorder(root1);
    cout << "Test case 1: ";
    for (int i : result1) {
        cout << i << " ";
    }
    cout << endl;

    // Test case 2
    Node* root2 = new Node(1);
    root2->children.push_back(new Node(2));
    root2->children.push_back(new Node(3));
    root2->children.push_back(new Node(4));
    root2->children.push_back(new Node(5));
    root2->children[1]->children.push_back(new Node(6));
    root2->children[1]->children.push_back(new Node(7));
    root2->children[2]->children.push_back(new Node(8));
    root2->children[3]->children.push_back(new Node(9));
    root2->children[3]->children.push_back(new Node(10));
    root2->children[1]->children[0]->children.push_back(new Node(11));
    root2->children[1]->children[1]->children.push_back(new Node(12));
    root2->children[2]->children[0]->children.push_back(new Node(13));
    root2->children[3]->children[0]->children.push_back(new Node(14));

    vector<int> result2 = solution.postorder(root2);
    cout << "Test case 2: ";
    for (int i : result2) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}