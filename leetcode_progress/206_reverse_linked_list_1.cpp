#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

// Recursive approach
class Solution {
    public: 
        ListNode *reverseList(ListNode *head){
            if(!head || !head->next){ return head;}

            ListNode *last = reverseList(head->next);
            head->next->next = head;
            head->next = nullptr;
            return last;
        }
};
// Iterative approach
class Solution2 {
    public: 
        ListNode *reverseList(ListNode *head){
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

int main(){
    ListNode *head = new ListNode(1);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(4);
    ListNode *node4 = new ListNode(5);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    Solution obj;
    ListNode *result = obj.reverseList(head);
    while(result){
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}