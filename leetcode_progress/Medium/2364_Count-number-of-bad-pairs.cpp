#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long goodPairs = 0;
        long long n = nums.size();
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            int key = nums[i] - i;
            goodPairs += freq[key]; //! Each time we see the same value again, it forms a good pair
            freq[key]++;
        }
        return (n * (n - 1)) / 2 - goodPairs;
    }
};
// 4 0 1 0
// 4 -> 1
// 0 -> 2
// 1 -> 1
int main(){
    Solution s;
    vector<int> nums = {4, 1, 3, 3};
    cout << s.countBadPairs(nums) << "\n";
    return 0;
}
