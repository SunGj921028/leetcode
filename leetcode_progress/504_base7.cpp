#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        int sign = (num < 0) ? 1 : 0; // 1: negative, 0: positive
        num = abs(num);
        string result = "";
        // Convertion
        while(num >= 7){
            result = to_string(num % 7) + result;
            num /= 7;
        }
        result = to_string(num) + result;
        if(sign == 1){
            result = "-" + result; // String cat
        }
        return result;
    }
};

int main(){
    Solution s;
    cout << s.convertToBase7(-7) << endl;
    return 0;
}