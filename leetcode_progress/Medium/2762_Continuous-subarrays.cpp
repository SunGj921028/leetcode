#include<bits/stdc++.h>

using namespace std;
//! Sliding window approach
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        // Map to maintain sorted frequency map of current window
        map<int, int> freq;
        int left = 0, right = 0;
        int n = nums.size();
        long long cnt = 0;

        while(right < n){
            //? Add the current element to the map
            freq[nums[right]]++;

            //? While window violates the condition |nums[i] - nums[j]| <= 2
            //? Shrink the window from the left
            //! freq.rbegin()->first gets the largest element in the frequency map
            //! freq.begin()->first gets the smallest element in the frequency map
            while(freq.rbegin()->first - freq.begin()->first > 2){
                freq[nums[left]]--;
                if(freq[nums[left]] == 0){
                    freq.erase(nums[left]);
                }
                left++;
            }

            //? Add count of all valid subarrays ending at right
            cnt += (right - left + 1);
            right++;
        }
    }
};

int main(){
    Solution sol;
    vector<int> nums = {5, 4, 2, 4};
    cout << sol.continuousSubarrays(nums) << endl;
    return 0;
}