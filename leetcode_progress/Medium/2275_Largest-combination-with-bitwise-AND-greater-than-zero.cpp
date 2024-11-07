#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int cnt = 0;
            for(auto candidate : candidates){
                // 1 << i shifts 1 to the i-th bit position, creating a mask (like 00010000 for i = 4).
                // candidate & (1 << i) checks if this bit is set by applying the mask; 
                // if the result is non-zero, then this bit is set in candidate.
                if(candidate & (1 << i)){ cnt++; }
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};

int main(){
    Solution solution;
    vector<int> candidates = {16, 17, 71, 62, 12, 24, 14};
    cout << solution.largestCombination(candidates) << endl;
    return 0;
}