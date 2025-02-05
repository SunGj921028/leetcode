#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diffCount = 0;
        int diffIdx1 = 0;
        int diffIdx2 = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                diffCount++;
                if(diffCount > 2){ return false; }
                else if(diffCount == 1){ diffIdx1 = i; }
                else if(diffCount == 2){ diffIdx2 = i; }
            }
        }
        return s1[diffIdx1] == s2[diffIdx2] && s1[diffIdx2] == s2[diffIdx1];
    }
};

int main(){
    Solution s;
    string s1 = "bank";
    string s2 = "kanb";
    cout << s.areAlmostEqual(s1, s2) << "\n";
    return 0;
}