#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<char> stack;
        for(auto c : s){
            if(stack.empty()){
                stack.push(c);
                continue;
            }

            if(c == 'B' && stack.top() == 'A'){ // AB
                stack.pop();
            }else if(c == 'D' && stack.top() == 'C'){
                stack.pop();
            }else{
                stack.push(c);
            }
        }
        return stack.size();
    }
};

int main(){
    Solution* obj = new Solution();
    string s = "ABFCACDB";
    string s2 = "ACBBD";
    cout << obj->minLength(s) << "\n";
    cout << obj->minLength(s2) << "\n";
    return 0;
}