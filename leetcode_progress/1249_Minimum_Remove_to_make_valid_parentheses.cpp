#include<iostream>
#include<string>

using namespace std;

class Solution{
    public:
        string minRemoveToMakeValid(string s){
            int openParenthesesCount = 0;
            for(auto &it : s){
                if(it == '('){
                    openParenthesesCount++;
                }else if(it == ')'){
                    if(!openParenthesesCount){
                        it = '*';
                    }else{
                        openParenthesesCount--;
                    }
                }
            }

            for(int i = s.length() - 1; i >= 0; i--){
                if(s[i] == '(' && openParenthesesCount > 0){
                    s[i] = '*';
                    openParenthesesCount--;
                }
            }

            // Second solution
            for(int i = 0;i < s.length(); i++){
                if(s[i] == '*'){
                    s.erase(s.begin() + i);
                    i--;
                }
            }
            return s;
        }
};