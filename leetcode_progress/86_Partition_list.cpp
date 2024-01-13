#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode *partition(ListNode *head, int x){
        ListNode *dummy1 = new ListNode(-1);
        ListNode *dummy2 = new ListNode(-1);
        // dummy1 is the head of the answer
        ListNode *p1 = dummy1;
        ListNode *p2 = dummy2;
        ListNode *p = head;
        while(p != NULL){
            if(p->val >= x){
                p2->next = p;
                p2 = p2->next;
            }else{
                p1->next = p;
                p1 = p1->next;
            }
            // 斷開原鏈表中每個節點與後面的鏈接
            ListNode *tmp = p->next;
            p->next = NULL;
            p = tmp;
        }
        // 將兩個鏈表連接起來
        p1->next = dummy2->next;
        return dummy1->next;
    }
};