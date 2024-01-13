#include<iostream>
#include<vector>

using namespace std;

// solution 1: my solution
class Solution1 {
    public:
        int maxSubArray(vector<int > &nums) {
            int sum = 0;
            int maxSum = INT_MIN;
            for(int i = 0; i < nums.size(); i++){
                sum += nums[i];
                maxSum = max(maxSum, sum);
                if(sum < 0){
                    sum = 0;
                }
            }
            return maxSum;
        }
};

// solution 2: 滑動窗口
class Solution2 {
public:
    int maxSubArray(vector<int > &nums) {
        int left = 0, right = 0;
        int windowSum = 0, maxSum = INT_MIN;
        while(right < nums.size()){
            // 扩大窗口并更新窗口内的元素和
            windowSum += nums[right];
            right++;

            // 更新答案
            maxSum = windowSum > maxSum ? windowSum : maxSum;
            // maxSum = max(windowSum, maxSum);

            // 判断窗口是否要收缩
            while(windowSum < 0) {
                // 缩小窗口并更新窗口内的元素和
                windowSum -=  nums[left];
                left++;
            }
        }
        return maxSum;
    }
};

// solution 3: DP
class Solution3 {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        // base case
        int dp_0 = nums[0];
        int dp_1 = 0, res = dp_0;

        for (int i = 1; i < n; i++) {
            // dp[i] = max(nums[i], nums[i] + dp[i-1])
            dp_1 = max(nums[i], nums[i] + dp_0);
            dp_0 = dp_1;
            // 顺便计算最大的结果
            res = max(res, dp_1);
        }
        
        return res;
    }
};

int main(){
    Solution1 s;
    vector<int> nums = {5,4,-1,7,8};
    cout << s.maxSubArray(nums) << endl;
    return 0;
}