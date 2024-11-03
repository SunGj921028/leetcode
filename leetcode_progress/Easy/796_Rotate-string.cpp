#include<bits/stdc++.h>

using namespace std;

//! The key insight is that when you concatenate a string with itself (s + s), 
//! it contains all possible rotations of the original string.
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()){ return false;}
        return (s + s).find(goal) != string::npos;
    }
};

int main(){
    Solution solution;
    string s = "abcde";
    string goal = "cdeab";
    string goal2 = "abced";
    cout << solution.rotateString(s, goal) << endl;
    cout << solution.rotateString(s, goal2) << endl;
    return 0;
}