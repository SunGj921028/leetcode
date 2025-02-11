#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = "";
        int targetLength = part.size();
        char lastCharInPart = part.back();

        for(char c : s){
            ans.push_back(c);

            if(c == lastCharInPart && ans.size() >= targetLength){ // At leasr stack of ans has the same length as part
                if(ans.substr(ans.size() - targetLength) == part){
                    ans.erase(ans.size() - targetLength);
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    string str = "daabcbaabcbc";
    string part = "abc";
    cout << s.removeOccurrences(str, part) << "\n";
    return 0;
}