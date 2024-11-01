#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string result = "";
        int repeat = 1;
        for(int i = 0; i < s.size(); i++){
            if(i != 0 && (s[i] == s[i - 1])){ repeat++; }
            else{ repeat = 1; }
            if(repeat < 3){ result += s[i]; }
            else{ continue; }
        }
        return result;
    }
};

int main(){
    Solution solution;
    string s = "leeetcode";
    cout << solution.makeFancyString(s) << endl;
    return 0;
}