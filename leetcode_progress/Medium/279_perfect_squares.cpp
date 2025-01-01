#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

// dp
class Solution1 {
    public: 
        int numSquares(int n){
            // 定义：和为 i 的平方数的最小数量是 dp[i]
            vector<int > dp(n + 1, INT_MAX);
            // base case
            dp[0] = 0;
            for(int i = 1;i <= n;i++){
                // dp[i] = i;
                for(int j = 1;j * j <= i;j++){
                    dp[i] = min(dp[i], dp[i - j * j] + 1);
                }
            }
            return dp[n];
        }
};

class Solution2 {
    public: 
        bool is_square(int n){
            double sq = sqrt(n);
            return ( sq == (int)sq );
        }
        int numSquares(int n){
            //Use Lagrange's four-square theorem and Legendre's three-square theorem
            // 4^k * (8m + 7) = 4 * (4^k * (2m + 1)) + 3
            while(n % 4 == 0){ n /= 4;}
            if(n % 8 == 7){ return 4;}
            if(is_square(n)){ return 1;}
            double sqrt_n = sqrt(n);
            for(int i = 1;i <= sqrt_n;i++){
                if(is_square(n - i * i)){ return 2;}
            }
            return 3;
        }
};