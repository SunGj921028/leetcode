#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        if(nums.size() <= 1){ return -1;}
        map<int, int> mp;
        sort(nums.begin(), nums.end()); // Ascending order
        int ans = -1;
        for(int num : nums){
            int sqrtNum = sqrt(num);
            if(sqrtNum * sqrtNum == num && mp.find(sqrtNum) != mp.end()){
                mp[num] = mp[sqrtNum] + 1;
                ans = max(ans, mp[num]);
            }else{
                mp[num] = 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {4, 3, 6, 16, 8, 2};
    cout << sol.longestSquareStreak(nums) << endl;
    return 0;
}