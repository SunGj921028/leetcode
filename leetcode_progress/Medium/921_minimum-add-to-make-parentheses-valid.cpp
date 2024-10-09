#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int add = 0;
        int need = 0;
        for(char c : s){
            if(c == '('){ need++;}
            else if(c == ')'){
                if(need == 0){ add++, need = 0;}
                else{ need--;}
            }
        }
        return (add + need);
    }
};

int main(){
    Solution* obj = new Solution();
    string s = "())";
    string s2 = "(((";
    string s3 = "()";
    string s4 = "()))((";
    cout << obj->minAddToMakeValid(s) << "\n";
    cout << obj->minAddToMakeValid(s2) << "\n";
    cout << obj->minAddToMakeValid(s3) << "\n";
    cout << obj->minAddToMakeValid(s4) << "\n";
    return 0;
}