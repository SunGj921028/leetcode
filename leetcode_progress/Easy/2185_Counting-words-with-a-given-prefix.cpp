#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for(int i = 0; i < words.size(); i++){
            if(words[i].find(pref) == 0){ cnt++;}
        }
        return cnt;
    }
};

int main(){
    Solution s;
    vector<string> words = {"pay", "attention", "practice", "attend"};
    cout << s.prefixCount(words, "at") << endl;
    return 0;
}