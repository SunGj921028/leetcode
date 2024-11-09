#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long minEnd(int n, int x) {
        long result = x;
        long remaining = n - 1;
        long position = 1;
        
        while (remaining) {
            if (!(x & position)) {
                result |= (remaining & 1) * position;
                remaining >>= 1;
            }
            position <<= 1;
        }
        
        return result;
    }
};

int main(){
    Solution s;
    cout << s.minEnd(3, 4) << endl;
    cout << s.minEnd(2, 7) << endl;
    return 0;
}