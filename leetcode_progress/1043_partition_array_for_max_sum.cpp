#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public: 
        int maxSumAfterPartitioning(vector<int>& arr, int k) {
            int n = arr.size();
            vector<int> dp(n + 1, 0);
            for (int i = 1; i <= n; ++i) {
                int maxVal = arr[i - 1];
                for (int j = 1; j <= k && i - j >= 0; ++j) {
                    maxVal = max(maxVal, arr[i - j]);
                    dp[i] = max(dp[i], dp[i - j] + maxVal * j);
                }
            }
            return dp[n];
        }
};

// int main() {
//     vector<int> arr = {1,15,7,9,2,5,10};
//     int k = 3;
//     int result = maxSumAfterPartitioning(arr, k);
//     cout << "The largest sum after partitioning is: " << result << endl;
//     return 0;
// }
