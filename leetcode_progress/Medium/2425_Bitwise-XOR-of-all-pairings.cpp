#include<bits/stdc++.h>

using namespace std;

//! XOR 的特性是：如果某個數出現偶數次，它的 XOR 結果為 0；如果出現奇數次，它會保留自身值。
//! 因此，我們只需要關注 nums1 和 nums2 中的元素，哪些會因為對應的次數為奇數而保留在最終 XOR 中。

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        // Initialize XOR results for both arrays
        int xor1 = 0;
        int xor2 = 0;

        // Get lengths of both arrays
        int len1 = nums1.size();
        int len2 = nums2.size();

        // If nums2 length is odd, each element in nums1 appears odd times in
        // final result
        if (len2 % 2 != 0) {
            for (int num : nums1) {
                xor1 ^= num;
            }
        }

        // If nums1 length is odd, each element in nums2 appears odd times in
        // final result
        if (len1 % 2 != 0) {
            for (int num : nums2) {
                xor2 ^= num;
            }
        }

        // Return XOR of both results
        return xor1 ^ xor2;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {2, 1, 3};
    vector<int> nums2 = {10, 2, 5, 0};
    cout << s.xorAllNums(nums1, nums2) << endl;
    return 0;
}