#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        unordered_map<char, string> mp;
        for(int i=0; i<26; i++){
            mp['a'+i] = to_string(i+1);
        }
        string str = "";
        int res = 0;
        // First transform
        for(char c: s){
            str += mp[c];
        }

        for(char c : str){
            res += c - '0';
        }

        while((--k) != 0){
            str = to_string(res);
            res = 0;
            for(char c : str){
                res += c - '0';
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    cout << s.getLucky("iiii", 1) << endl;
    cout << s.getLucky("leetcode", 2) << endl;
    cout << s.getLucky("zbax", 2) << endl;
    return 0;
}