#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        char st[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        int n = str1.length(), m = str2.length();
        while(i < n && j < m){
            if(str1[i] == str2[j] || st[(str1[i] - 'a' + 1) % 26] == str2[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        if(j == m){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    Solution s;
    string str1 = "abc";
    string str2 = "ad";
    cout << s.canMakeSubsequence(str1, str2) << endl;
    return 0;
}