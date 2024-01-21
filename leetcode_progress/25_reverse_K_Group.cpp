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
        ListNode *reverseKGroup(ListNode *head, int k){
            if(!head){ return nullptr;}
            ListNode *a, *b;
            a = b = head;
            // if list has less than k nodes, then no need to reverse
            for(int i = 0;i < k;i++){
                if(!b){ return head;}
                b = b->next;
            }
            // reverse the first k nodes
            ListNode *newHead = reverse(a, b);
            a->next = reverseKGroup(b, k);
            return newHead;
        }

        ListNode *reverse(ListNode *a, ListNode *b){
            ListNode *prev, *curr, *next;
            prev = nullptr;
            curr = a;
            next = a;
            while(curr != b){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }
};

class Solution2 {
    public: 
        ListNode *successor = nullptr;
        ListNode *reverseKGroup(ListNode *head, int k){
            if(!head){ return nullptr;}
            ListNode *b;
            b = head;
            // if list has less than k nodes, then no need to reverse
            for(int i = 0;i < k;i++){
                if(!b){ return head;}
                b = b->next;
            }
            // reverse the first k nodes
            ListNode *newHead = reverseN(head, k);
            head->next = reverseKGroup(successor, k);
            return newHead;
        }

        ListNode *reverseN(ListNode *head, int n){
            if (n == 1) {
                successor = head->next;
                return head;
            }
            ListNode* last = reverseN(head->next, n - 1);
            head->next->next = head;
            head->next = successor;
            return last;
        }
};