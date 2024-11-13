#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;

        for(int i = 0; i < nums.size() - 1; i++){
            auto up = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            auto low = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]); //! up 和 low 都是指標
            ans += (up - low); //! up - low 計算在 [lower, upper] 範圍內的元素個數
        }
        return ans;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {0, 1, 7, 4, 4, 5};
    int lower = 3;
    int upper = 6;
    cout << solution.countFairPairs(nums, lower, upper) << endl;
    return 0;
}