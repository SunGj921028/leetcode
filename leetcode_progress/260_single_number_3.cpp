#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
        vector<int > singleNumber(vector<int > &nums){
            int ans = 0;
            for(auto i : nums){
                ans ^= i;
            }
            int bit = 1;
            while((bit & ans) == 0){
                bit <<= 1;
            }
            int a = 0;
            int b = 0;
            for(auto i : nums){
                if((i & bit) == 0){
                    a ^= i;
                }else{
                    b ^= i;
                }
            }
            return {a, b};
        }
};