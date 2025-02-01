#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool isSpecial = false;
        if(nums.size() == 1){ return true; }
        for(int i = 0; i < nums.size() - 1; i++){
            cout << !(nums[i] % 2) << " " << (nums[i + 1] % 2) << endl;
            if(!(nums[i] % 2) == (nums[i + 1] % 2)){
                isSpecial = true;
            }else{
                isSpecial = false;
                break;
            }
        }
        return isSpecial;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2, 1, 4};
    cout << s.isArraySpecial(nums) << endl;
    return 0;
}