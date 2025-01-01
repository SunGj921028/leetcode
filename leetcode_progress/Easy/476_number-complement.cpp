#include<bits/stdc++.h>

using namespace std;

// 5 -> 0101
// 2 -> 0010
// 5 & 2 -> 0000

class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1;
        unsigned int mask = ~0; // All bits is 1

        // If the result is non-zero, it means there are common bits set, so the loop continues.
        while(num & mask){
            mask <<= 1;
        }

        return ~mask & ~num;
    }
};

int main(){
    Solution s;
    cout << s.findComplement(5) << endl;
    return 0;
}