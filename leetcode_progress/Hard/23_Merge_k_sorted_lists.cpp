#include<iostream>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode * mergeKLists(vector<ListNode*> &lists){
        if (lists.empty()) return nullptr;
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;
        // 優先級隊列 (最小堆)
        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> pq( [] (ListNode* a, ListNode* b){
            return a->val > b->val;
        });
        // 將 k 個鏈表的頭節點加入優先級隊列
        for (auto node : lists){
            if (node) pq.push(node);
        }

        while(!pq.empty()){
            ListNode *node = pq.top();// 最小節點
            pq.pop();
            p->next = node;
            if (node->next) pq.push(node->next);
            p = p->next;
        }

        return dummy->next;
    }
};
