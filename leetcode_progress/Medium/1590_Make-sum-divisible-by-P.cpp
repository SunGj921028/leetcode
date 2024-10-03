#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long sum = 0;
        int remainder = 0;
        // Calculate the total sum of the array
        // Calculate the remainder when divided by p
        for(int i : nums){
            sum += i;
        }
        remainder = sum % p;
        if(remainder == 0){ return 0;}

        // The sum of the removed subarray should have the same remainder as the total sum % p
        // We use a hashmap to store the prefix sum modulo values
        unordered_map<int, int> prefixMod;
        prefixMod[0] = -1; // Initialize for handling full prefix
        long prefixSum = 0;
        int minLen = nums.size();

        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];
            int currentMod = prefixSum % p;
            int targetMod = (currentMod - remainder + p) % p;

            if(prefixMod.find(targetMod) != prefixMod.end()){ // Can be find => current subarray can be removed
                minLen = min(minLen, i - prefixMod[targetMod]);
            }
            prefixMod[currentMod] = i;
        }

        return minLen == nums.size() ? -1 : minLen;
    }
};

int main(){
    Solution* obj = new Solution();
    vector<int> nums = {3,1,4,2};
    vector<int> num2 = {6, 3, 5, 2};
    vector<int> num3 = {1000000000,1000000000,1000000000};
    int p = 6;
    int p2 = 9;
    int p3 = 3;
    cout << obj->minSubarray(nums, p) << "\n";
    cout << obj->minSubarray(num2, p2) << "\n";
    cout << obj->minSubarray(num3, p3) << "\n";
    return 0;
}