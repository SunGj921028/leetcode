#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;
        int m = a.size(), n = b.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        for(int i = 0;i < max(m, n) || carry > 0; i++){
            int val = carry;
            val += (i < m) ? (a[i] - '0') : 0;
            val += (i < n) ? (b[i] - '0') : 0;
            result += (val % 2) + '0'; // to_string(val % 2)
            carry = val / 2;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main(){
    Solution s;
    cout << s.addBinary("11", "1") << endl;
    cout << s.addBinary("1010", "1011") << endl;
    return 0;
}