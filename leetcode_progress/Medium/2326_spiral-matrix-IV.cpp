#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//? https://leetcode.com/problems/spiral-matrix-iv/description/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int> > res(m, vector<int>(n, -1));
        int dir[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dirIdx = 0;
        int i = 0, j = 0;
        ListNode *temp = head;
        while(temp != nullptr){
            // Normal move to add the value into matrix
            res[i][j] = temp->val;
            temp = temp->next;
            // Judge the direction
            int nextI = i + dir[dirIdx][0];
            int nextJ = j + dir[dirIdx][1];
            if(nextI < 0 || nextI >= m || nextJ < 0 || nextJ >= n || res[nextI][nextJ] != -1) {
                dirIdx = (dirIdx + 1) % 4; // To switch the direction
                nextI = i + dir[dirIdx][0];
                nextJ = j + dir[dirIdx][1];
            }
            i = nextI;
            j = nextJ;
        }
        return res;
    }
};

int main(){
    Solution solution;
    ListNode* head = new ListNode(3);
    head->next = new ListNode(0);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(6);
    head->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next->next->next->next->next->next->next = new ListNode(0);
    
    vector<vector<int>> result = solution.spiralMatrix(3, 5, head);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}