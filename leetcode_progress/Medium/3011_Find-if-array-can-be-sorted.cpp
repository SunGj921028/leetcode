#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int countBits(int num){
        return bitset<32>(num).count();
    }
public:
    bool canSortArray(vector<int> &nums) {
        uint8_t n = nums.size();
        uint16_t pmax = 0, cmin = 0, cmax = 0; // previous max, current min, current max
        uint8_t pcnt = 0;
        for (uint16_t v : nums) {
            int setBits = countBits(v);
            if (pcnt == setBits) {
                cmin = min(cmin, v);
                cmax = max(cmax, v);
            } else if (cmin < pmax) {
                return false;
            } else {
                pmax = cmax;
                cmin = cmax = v;
                pcnt = setBits;
            }
        }
        return (cmin >= pmax);
    }
};

int main(){
    Solution solution;
    vector<int> nums = {8, 4, 2, 30, 15};
    vector<int> nums2 = {3, 16, 8, 4, 2};
    cout << solution.canSortArray(nums) << endl;
    cout << solution.canSortArray(nums2) << endl;
    return 0;
}