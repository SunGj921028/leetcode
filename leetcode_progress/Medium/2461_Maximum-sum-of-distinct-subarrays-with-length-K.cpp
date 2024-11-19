#include<bits/stdc++.h>

using namespace std;

//! Sliding Window
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int > fre;
        long long curSum = 0, maxSum = 0;
        int begin = 0;

        for(int end = 0; end < n; end++){
            if(fre.find(nums[end]) == fre.end()){
                curSum += nums[end];
                fre.insert(nums[end]);

                if(end - begin + 1 == k){
                    maxSum = max(maxSum, curSum);
                    curSum -= nums[begin];
                    fre.erase(nums[begin]);
                    begin++;
                }
            }else{
                while(nums[begin] != nums[end]){
                    curSum -= nums[begin];
                    fre.erase(nums[begin]);
                    begin++;
                }
                begin++;
            }
        }
        return maxSum;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {1, 5, 4, 2, 9, 9, 9};
    int k = 3;
    cout << solution.maximumSubarraySum(nums, k) << endl;
    return 0;
}