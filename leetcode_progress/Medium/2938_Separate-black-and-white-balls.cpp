#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        int black = 0; // The number of black before meeting with a white ball
        long long cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                cnt += black;
            }else{
                black++;
            }
        }
        return cnt;
    }
};

int main(){
    Solution* obj = new Solution();
    string s = "101";
    string s1 = "100";
    cout << obj->minimumSteps(s) << "\n";
    cout << obj->minimumSteps(s1) << "\n";
    return 0;
}