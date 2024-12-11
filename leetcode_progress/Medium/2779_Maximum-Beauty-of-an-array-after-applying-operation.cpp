#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int freq[100001] = {0};
        int xMax = 0, xMin = 1e6;
        for(int x: nums){
            freq[x]++;
            xMax = max(xMax, x);
            xMin = min(xMin, x);
        }
        int cnt = 0, maxCnt = 0;
        for(int l = xMin, r = xMin; r <= xMax; r++){
            cnt += freq[r];
            while(r - l > 2 * k){
                cnt -= freq[l];
                l++;
            }
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {4, 6, 1, 2};
    int k = 2;
    cout << sol.maximumBeauty(nums, k) << endl;
    return 0;
}