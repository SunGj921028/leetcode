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

//? https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a % b);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *temp = head;
        while(temp != nullptr && temp->next != nullptr) {
            int a = temp->val;
            int b = temp->next->val;
            int commonDivisor = gcd(a, b);
            ListNode *newNode = new ListNode(commonDivisor);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
        return head;
    }
};

int main(){
    Solution solution;
    ListNode* head = new ListNode(18);
    head->next = new ListNode(6);
    head->next->next = new ListNode(10);
    head->next->next->next = new ListNode(3);

    head = solution.insertGreatestCommonDivisors(head);

    // Print the resulting list
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}