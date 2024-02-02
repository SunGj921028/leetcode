#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public: 
        int removeDuplicates(vector<int>& nums) {
            if (nums.size() == 0) return 0;
            // i is the slow pointer and j is the fast pointer
            int i = 0;
            for (int j = 1; j < nums.size(); j++) {
                if (nums[j] != nums[i]) {
                    i++;
                    nums[i] = nums[j];
                }
            }
            return i + 1;
        }
};