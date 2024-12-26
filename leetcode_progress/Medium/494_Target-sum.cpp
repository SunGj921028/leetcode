#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<string, int> memo;

    int dp(vector<int> & nums, int i, int remain){
        // base case
        if(i == nums.size()){
            if(remain == 0){ return 1;}
            return 0;
        }

        string key = to_string(i) + "," + to_string(remain);
        if(memo.count(key)){
            return memo[key];
        }

        int result = dp(nums, i + 1, remain - nums[i]) + dp(nums, i + 1, remain + nums[i]);
        memo[key] = result;
        return result;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        if(nums.empty()){ return 0;}
        return dp(nums, 0, target);
    }
};

int main(){
    Solution solution;

    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    int result = solution.findTargetSumWays(nums, target);
    cout << result << endl;

    return 0;
}