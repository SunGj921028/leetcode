#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1 == "0"){ return num2;}
        if(num2 == "0"){ return num1;}
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string result = "";
        int carry = 0;
        int m = num1.size(), n = num2.size();

        for(int i = 0;i < max(m, n) || carry > 0 ; i++){
            int val = carry;
            val += (i < m) ? (num1[i] - '0') : 0;
            val += (i < n) ? (num2[i] - '0') : 0;
            result += (val % 10) + '0';
            carry = val / 10;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main(){
    Solution s;
    cout << s.addStrings("11", "123") << endl;
    cout << s.addStrings("456", "77") << endl;
    cout << s.addStrings("0", "0") << endl;
    return 0;
}