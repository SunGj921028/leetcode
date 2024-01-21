#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

class Solution {
    public: 
        bool isPalindrome(ListNode *head){
            // 先利用快慢指針找到中間節點 以減少空間複雜度
            ListNode *slow = head;
            ListNode *fast = head;
            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
            }

            // 如果fast指針沒有指向null，說明鏈表長度為奇數，slow還要再前進一步
            if(fast){ slow = slow->next; }
            ListNode *left = head;
            ListNode *right = reverse(slow);
            // to recover the list
            ListNode *q = right;
            while(right){
                if(left->val != right->val){ return false;}
                left = left->next;
                right = right->next;
            }
            reverse(q);
            return true;
        }

        ListNode *reverse(ListNode *head){
            ListNode *prev = nullptr;
            ListNode *curr = head;
            while(curr){
                ListNode *nextTemp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextTemp;
            }
            return prev;
        }
};