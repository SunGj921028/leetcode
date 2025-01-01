#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    const char map[16] = {'0', '1', '2','3', 
                            '4', '5', '6', '7', 
                            '8', '9', 'a', 'b', 
                            'c', 'd', 'e', 'f'};
    string toHex(int num) {
        if(num == 0){ return "0";}
        string result = "";
        while(num != 0){
            result = string(1, map[num & 15]) + result;
            num = (unsigned)num >> 4; // equals to (num / 16)
        }
        return result;
    }
};

int main(){
    Solution s;
    cout << s.toHex(26) << endl;
    return 0;
}