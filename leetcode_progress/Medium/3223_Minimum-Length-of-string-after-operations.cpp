#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> count; // Frequency of characters in string.
        for(char c : s){ count[c]++;}

        int lengthToMinus = 0;
        for(auto & entry : count){
            while(entry.second >= 3){
                lengthToMinus += 2;
                entry.second -= 2;
            }
        }
        return s.size() - lengthToMinus;
    }
};

int main(){
    Solution s;
    cout << s.minimumLength("abaacbcbb") << endl;
    return 0;
}