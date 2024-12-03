#include<bits/stdc++.h>

using namespace std;

class Solution2 {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.length();
        int m = spaces.size();
        string newStr(n + m, ' ');

        int i = 0, j = 0; // Two Pointers
        int idx = 0;
        for (int spc : spaces) {
            while (i < spc) {
                newStr[idx++] = s[i];
                i++;
            }
            newStr[idx++] = ' ';
            j++;
        }

        // For last finishing
        while (i < n) {
            newStr[idx++] = s[i];
            i++;
        }

        return newStr;
    }
};

//! Run time error
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        for(int i = 0, idx = 0; i < s.size(); i++){
            if(i == spaces[idx]){ ans += ' ', idx++; } //? Judge of if condition is too computationally expensive
            ans += s[i];
        }
        return ans;
    }
};

int main(){
    Solution s;
    string sentence = "LeetcodeHelpsMeLearn";
    vector<int> spaces = {8, 13, 15};
    cout << s.addSpaces(sentence, spaces) << endl;
    return 0;
}