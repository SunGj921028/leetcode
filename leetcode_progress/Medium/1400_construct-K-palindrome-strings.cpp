#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k){ return false; }
        int oddCount = 0;
        vector<int> charFreq(26, 0);
        for(char c : s){
            charFreq[c - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(charFreq[i] % 2 == 1){
                oddCount++;
            }
        }
        return oddCount <= k;
    }
};

int main(){
    Solution s;
    string str = "leetcode";
    int k = 3;
    cout << s.canConstruct(str, k) << endl;
    return 0;
}