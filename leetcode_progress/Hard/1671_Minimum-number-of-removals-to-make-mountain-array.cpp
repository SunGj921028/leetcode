#include<bits/stdc++.h>

using namespace std;

//! Longest Increasing Subsequence (LIS) up to each point to form the "up" side.
//! Longest Decreasing Subsequence (LDS) from each point to form the "down" side.

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int > LIS(n, 1), LDS(n, 1);

        // Compute LIS up to each index
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }

        // Compute LDS from each index
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[i] > nums[j]) {
                    LDS[i] = max(LDS[i], LDS[j] + 1);
                }
            }
        }

        int maxMountainLength = 0;
        // Find the maximum mountain length
        //? A valid peak must have LIS[i] > 1 and LDS[i] > 1
        //? For each valid peak, calculate the mountain length LIS[i] + LDS[i] - 1 and track the maximum mountain length.
        for (int i = 1; i < n - 1; ++i) {
            if (LIS[i] > 1 && LDS[i] > 1) {  // Valid peak
                maxMountainLength = max(maxMountainLength, LIS[i] + LDS[i] - 1);
            }
        }

        return n - maxMountainLength; //? minimum removals
    }
};

int main(){
    Solution solution;
    vector<int> nums = {1, 3, 1};
    cout << solution.minimumMountainRemovals(nums) << endl;
    return 0;
}