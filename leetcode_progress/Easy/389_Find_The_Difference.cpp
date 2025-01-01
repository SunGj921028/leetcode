#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution{
    public:
        char findTheDifference(string s, string t){
            if (s.empty())  return t[0];
            char ans = 0;
            for(char c : s){
                ans ^= c;
            }
            for(char c : t){
                ans ^= c;
            }
            return ans;
        }
};

class Solution2{
    public:
        char findTheDifference(string s, string t){
            if (s.empty())  return t[0];
            vector<int> count(26, 0);
            for(auto &it : s){ count[it - 'a']++; }
            for(auto &it : t){ count[it - 'a']--; }
            for(int i = 0;i < 26; i++){
                if(count[i] == 1){ return i + 'a';}
            }
            return 'a';
        }
};