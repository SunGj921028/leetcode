#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        // 0 -> comes from 2 * 5
        return (n == 0) ? 0 : (n / 5) + trailingZeroes(n / 5);
    }
};

int main(){
    Solution s;
    cout << s.trailingZeroes(5) << endl;
    return 0;
}