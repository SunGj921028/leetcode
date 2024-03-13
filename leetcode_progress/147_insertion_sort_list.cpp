#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

class Solution{
    public:
        ListNode* insertionSortList(ListNode* head){
            ListNode* dummy = new ListNode(-1);
            dummy->next = head;
            ListNode* prev = dummy;
            ListNode* curr = head;

            while(curr){
                if((curr->next->val < curr->val) && curr){
                    // find the front to insert
                    while(prev->next && prev->next->val < curr->next->val){
                        prev = prev->next;
                    }
                    ListNode* temp = prev->next;
                    prev->next = curr->next;
                    curr->next = curr->next->next;
                    prev->next->next = temp;

                    prev = dummy;
                }else{
                    curr = curr->next;
                }
            }
            return dummy->next;
        }
};

int main(){
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution sol;
    ListNode* result = sol.insertionSortList(head);
    while(result){
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}