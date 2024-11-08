#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int xorr = nums[0];
        int maxXOR = pow(2, maximumBit) - 1;
        for(int i = 1; i < n; i++){
            xorr ^= nums[i];
        }
        vector<int> result(n);
        for(int i = 0; i < n; i++){
            result[i] = xorr ^ maxXOR;
            xorr ^= nums[n - i - 1];
        }
        return result;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {0,1,1,3};
    int maximumBit = 2;
    vector<int> result = solution.getMaximumXor(nums, maximumBit);
    for(auto res : result){
        cout << res << " ";
    }
    cout << endl;
    return 0;
}