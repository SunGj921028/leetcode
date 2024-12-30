#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1);
        dp[0] = 1;
        int MOD = 1e9 + 7;

        for(int end = 1; end <= high; end++){
            if(end >= zero){
                dp[end] = (dp[end] + dp[end - zero]);
            }
            if(end >= one){
                dp[end] = (dp[end] + dp[end - one]);
            }
            dp[end] %= MOD;
        }

        int ans = 0;
        for(int i = low; i <= high; i++){
            ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};

int main(){
    int low = 2, high = 3, zero = 1, one = 2;
    Solution s;
    int ans = s.countGoodStrings(low, high, zero, one);
    cout << ans << endl;
    return 0;
}