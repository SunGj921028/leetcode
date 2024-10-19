#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        string str = "0";
        // Make the string Sn
        for(int i = 2; i <= n; i++){
            int curSize = str.size();
            str += "1";
            for(int j = curSize - 1; j >= 0; j--){
                if(str[j] == '0'){
                    str += "1";
                } else {
                    str += "0";
                }
            }
        }

        return str[k - 1];
    }
};

class SolutionForSpeed {
public:
    char findKthBit(int n, int k) {
    if (n == 1) {
        return '0';
    }
    
    int len = (1 << n) - 1; 
    int mid = len / 2 + 1;  
    
    if (k == mid) {
        return '1';
    }
    
    if (k < mid) {
        return findKthBit(n - 1, k);
    }
    
    char bit = findKthBit(n - 1, len - k + 1);
    return bit == '0' ? '1' : '0';

    }
};

int main(){
    Solution sol;
    cout << sol.findKthBit(3, 1) << endl;
    cout << sol.findKthBit(4, 11) << endl;
    cout << sol.findKthBit(2, 3) << endl;
    return 0;
}