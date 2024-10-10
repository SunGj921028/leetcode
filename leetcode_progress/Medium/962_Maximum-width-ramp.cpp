#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int > stack;

        // Step1: Build a decreasing stack of indices
        for(int i = 0; i < nums.size(); i++){
            if(stack.empty() || nums[stack.top()] > nums[i]){
                stack.push(i);
            }
        }
        int maxWidth = 0;
        // Step2: Traverse the array from right to left
        for(int j = nums.size() - 1; j >= 0; j--){
            while(!stack.empty() && nums[stack.top()] <= nums[j]){
                maxWidth = max(maxWidth, j - stack.top());
                stack.pop();
            }
        }
        return maxWidth;
    }
};

int main(){
    Solution* obj = new Solution();
    vector<int> nums = {6,0,8,2,1,5};
    cout << obj->maxWidthRamp(nums) << "\n";
    return 0;
}