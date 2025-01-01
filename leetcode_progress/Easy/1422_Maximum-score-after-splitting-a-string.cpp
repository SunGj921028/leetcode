#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int ones = count(s.begin(), s.end(), '1');

        int ans = 0;
        int zeros = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '1') {
                ones--;
            } else {
                zeros++;
            }
            ans = max(ans, zeros + ones);
        }
        
        return ans;
    }
};

int main(){
    // string s = "011101";
    // string s = "00111";
    // string s = "1111";
    // string s = "000";
    string s = "111111";
    Solution sol;
    int ans = sol.maxScore(s);
    cout << ans << endl;
    return 0;
}