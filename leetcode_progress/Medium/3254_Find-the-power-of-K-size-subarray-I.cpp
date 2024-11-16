#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> result;
        int n = nums.size();
        for(int i = 0; i < n - (k - 1); i++){
            int check = 0;
            for(int j = 0; j < (k - 1); j++){
                if(nums[i + j] >= nums[i + j + 1] || (nums[i + j + 1] - nums[i + j]) > 1){
                    result.push_back(-1);
                    check = 0;
                    break;
                }else{
                    check = 1;
                }
            }
            if(check || n == 1 || k == 1){
                result.push_back(nums[i + (k - 1)]);
            }
        }
        return result;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 3, 2, 5};
    int k = 3;
    vector<int> result = solution.resultsArray(nums, k);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}