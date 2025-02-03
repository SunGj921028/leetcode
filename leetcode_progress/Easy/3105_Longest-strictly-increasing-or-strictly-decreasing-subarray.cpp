#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int ansIncreasing = 1, ansDecreasing = 1;
        int len = nums.size();
        for(int i = 0; i < len - 1; i++){
            if(nums[i] < nums[i + 1]){
                ans = max(ans, ++ansIncreasing);
                ansDecreasing = 1;
            }else if(nums[i] > nums[i + 1]){
                ans = max(ans, ++ansDecreasing);
                ansIncreasing = 1;
            }else{
                ansDecreasing = 1;
                ansIncreasing = 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 4, 3, 3, 2};
    cout << s.longestMonotonicSubarray(nums) << "\n";
    return 0;
}