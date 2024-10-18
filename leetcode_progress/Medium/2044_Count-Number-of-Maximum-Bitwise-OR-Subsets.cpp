#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int count = 0;
    void backtrack(const vector<int> &nums, int index, int currentOR, int maxOR){
        if(currentOR == maxOR){ count++;}
        for(int i = index; i < nums.size(); i++){
            backtrack(nums, i + 1, currentOR | nums[i], maxOR);
        }
        return;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        // Compute Maximum OR
        int maxOR = 0;
        for(auto n : nums){
            maxOR |= n;
        }
        // Backtracking
        backtrack(nums, 0, 0, maxOR);
        // Base Case

        return count;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3, 1};
    cout << sol.countMaxOrSubsets(nums) << endl;
    return 0;
}