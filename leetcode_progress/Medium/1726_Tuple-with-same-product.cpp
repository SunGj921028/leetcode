#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productCount;
        int n = nums.size();
        for(int i = 0 ; i < n; i++){
            for(int j = i + 1 ; j < n; j++){
                productCount[nums[i] * nums[j]]++;
            }
        }
        int ans = 0;
        for(auto& entry : productCount){
            int count = entry.second;
            if(count > 1){
                //! 從 count 對中任意選兩對數組來構成四元數組 C(count, 2) = count * (count - 1) / 2
                ans += 8 * count * (count - 1) / 2; 
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2, 3, 4, 6};
    cout << s.tupleSameProduct(nums) << "\n";
    return 0;
}