#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n, 0);
        for(int i = 0; i < n; i++){
            prefix[i] = (i > 0 ? prefix[i - 1] : 0) + nums[i];
        }
        

        int count = 0;
        for(int idx = 0; idx < n - 1; idx++){
            if(prefix[idx] >= prefix[n - 1] - prefix[idx]){ count++;}
        }
        return count;
    }
};

int main(){
    Solution s;
    // vector<int> nums = {10, 4, -8, 7};
    vector<int> nums = {2, 3, 1, 0};
    cout << s.waysToSplitArray(nums) << endl;
    return 0;
}