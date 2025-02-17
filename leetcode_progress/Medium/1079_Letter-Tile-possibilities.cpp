#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ans = 0;
    vector<bool> used;
    int numTilePossibilities(string tiles) {
        vector<char> nums(tiles.begin(), tiles.end());
        sort(nums.begin(), nums.end());
        used = vector<bool>(nums.size(), false);
        backtrack(nums);
        return ans - 1;
    }

    void backtrack(vector<char> nums){
        ans++;

        for(int i = 0; i < nums.size(); i++){
            if(used[i]){ continue; }
            //! 剪枝（pruning） 的技巧，讓相同的字母按照特定順序選擇，避免重複計算排列組合
            if(i > 0 && nums[i] == nums[i - 1] && !used[i - 1]){ continue; }

            used[i] = true;
            backtrack(nums);
            used[i] = false;
        }
    }
};

int main(){
    Solution s;
    cout << s.numTilePossibilities("AAABBC") << endl;
    return 0;
}