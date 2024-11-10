#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> count(32, 0);
        int start = 0, end = 0, minLength = INT_MAX;

        while (end < nums.size()) {
            updateBits(count, nums[end], 1);
            while (start <= end && getVal(count) >= k) {
                minLength = min(minLength, end - start + 1);
                updateBits(count, nums[start], -1);
                start++;
            }
            end++;
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
private:
    void updateBits(vector<int>& count, int num, int val) {
        for (int i = 0; i < 32; i++) {
            if ((num >> i) & 1) { // 將當前的 num 每個 bit (共 32 個)逐一檢查並判斷是否為 1，記錄在 count 中
                count[i] += val; // val -> 1 (增加) or -1 (減少)
            }
        }
    }

    int getVal(const vector<int>& count) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (count[i] > 0) {
                ans |= (1 << i); // 1 << i 表示在第 i 位的位置設為 1，其他位元位置為 0, ans |= (1 << i) 使用「或」運算將 ans 的第 i 位設為 1
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 2, 3};
    int k = 2;
    cout << s.minimumSubarrayLength(nums, k) << endl;
    return 0;
}