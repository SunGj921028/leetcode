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
    public: 
        ListNode* deleteDuplicates(ListNode *head){
            if(head == nullptr){ return head; }
            ListNode *slow = head;
            ListNode *fast = head;
            while(fast != nullptr){
                if(slow->val != fast->val){
                    slow->next = fast;
                    slow = slow->next;
                }else{
                    fast = fast->next;
                }
            }
            slow->next = nullptr;
            return head;
        }
};