#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int find(int n,vector<int> &dp){
        if(n==3) return 3;
        if(n==2) return 2;
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=find(n-1,dp)+find(n-2,dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return find(n,dp);
    }
};

int main() {
    Solution solution;
    int n = 5;
    std::cout << solution.climbStairs(n) << std::endl;
    return 0;
}