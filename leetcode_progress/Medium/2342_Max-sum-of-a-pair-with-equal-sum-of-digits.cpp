#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int sumOfDigits(int num){
        int sum = 0;
        while(num){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, vector<int>> mp;
        for(int num : nums){
            mp[sumOfDigits(num)].push_back(num);
        }

        int maxSum = -1;
        for(auto& entry : mp){
            vector<int>& v = entry.second;
            if(v.size() < 2) continue;
            sort(v.begin(), v.end(), greater<int>());
            maxSum = max(maxSum, v[0] + v[1]);
        }
        return maxSum;
    }
};

int main(){
    Solution s;
    vector<int> nums = {18, 43, 36, 13, 7};
    cout << s.maximumSum(nums) << "\n";
    return 0;
}