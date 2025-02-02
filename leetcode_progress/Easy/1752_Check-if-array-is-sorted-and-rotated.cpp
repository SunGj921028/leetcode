#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0 ; i < len ; i++){
            bool canBeSorted = true;
            int temp = len - 1;
            int j = i;
            while(temp--){
                if(nums[j] > nums[(j + 1) % len]){ canBeSorted = false; break; }
                j = (j + 1) % len;
            }
            if(canBeSorted){ return true; }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3, 4, 5, 1, 2};
    cout << s.check(nums) << endl;
    return 0;
}