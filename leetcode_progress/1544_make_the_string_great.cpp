#include<iostream>
#include<string>

using namespace std;

class Solution1{
    public:
        bool isGreat(string s, int idx){
            if(s[idx] >= 'a' && s[idx] <= 'z' && s[idx + 1] == s[idx] - 32 || 
                s[idx] >= 'A' && s[idx] <= 'Z' && s[idx + 1] == s[idx] + 32){
                return true;
            }
            return false;
        }

        string makeGood(string s){
            string sc = s;
            int flag = 0;
            while(flag == 0 && sc.length() > 0){
                flag = 1;
                for(int i = 0;i < sc.length();i++){
                    if(isGreat(sc, i)){
                        sc.erase(i, 2);
                        flag = 0;
                        break;
                    }
                }
            }
            return sc;
        }
};

// Stack based solution
class Solution2{
    public:
        string makeGood(string s){
            string ans = "";
            for(char c : s){
                if(!ans.empty() && abs(ans.back() - c) == 32){
                    ans.pop_back(); // remove the last element
                }else{
                    ans.push_back(c);
                }
            }
            return ans;
        }
};

// Stack Solution 2
class Solution3{
    public:
        string makeGood(string s){
            string ans;
            for(char c : s){
                if(!ans.empty() && (toupper(c) == toupper(ans.back())) && (c != ans.back()) ){
                    ans.pop_back(); // remove the last element
                }else{
                    ans.push_back(c);
                }
            }
            return ans;
        }
};