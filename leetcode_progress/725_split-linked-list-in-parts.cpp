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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k);

        // Calculate the total length of the list
        int len = 0;
        ListNode *temp = head;
        while(temp != nullptr){
            len++;
            temp = temp->next;
        }

        int splitSize = len / k;
        int remainderExtraSize = len % k; // First remainderExtraSize of part has one extra node

        ListNode *prev = nullptr;
        temp = head;
        for(int i = 0 ; i < k; i++){
            ListNode * newPart = temp;
            int currentSize = splitSize;
            if(remainderExtraSize > 0){
                currentSize++;
                remainderExtraSize--;
            }

            //! traverse to end of new part
            int count = 0;
            while(count < currentSize){
                prev = temp;
                if(temp != nullptr){
                    temp = temp->next;
                }
                count++;
            }

            if(prev != nullptr){
                prev->next = nullptr;
            }

            res[i] = newPart;
        }
        return res;
    }
};