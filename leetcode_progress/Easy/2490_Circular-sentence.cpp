#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence.back() == sentence.front()){
            for(int  i = 0; i < sentence.size(); ++i){
                if(sentence[i] == ' '){
                    if(sentence[i - 1] != sentence[i + 1]){ return false;}
                }
            }
            return true;
        }
        return false;
    }
};

int main(){
    Solution solution;
    string sentence = "leetcode exercises sound delightful";
    cout << solution.isCircularSentence(sentence) << endl;
    return 0;
}