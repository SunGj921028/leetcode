#include<bits/stdc++.h>

using namespace std;

//? https://leetcode.com/problems/count-the-number-of-consistent-strings/description/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        bool notCosistent = false;
        for(auto str : words){
            notCosistent = false;
            for(auto c : str){
                if(allowed.find(c) > 26){ notCosistent = true; break;}
            }
            if(!notCosistent){ count++;}
        }
        return count;
    }
};

class Solution2{
public: 
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> mp;
        for(auto c : allowed){
            mp[c] = 1;
        }

        int count = 0;
        bool notConsistent = false;
        for(auto s : words){
            notConsistent = false;
            for(auto c : s){
                if(mp[c] != 1){ notConsistent = true; break;}
            }
            if(!notConsistent){ count++;}
        }
        return count;
    }
};

int main(){
    Solution solution;
    Solution2 solution2;
    string allowed = "ab";
    string allowed2 = "abc";
    string allowed3 = "cad";
    vector<string> words = {"ad","bd","aaab","baa","badab"};
    vector<string> words2 = {"a","b","c","ab","ac","bc","abc"};
    vector<string> words3 = {"cc","acd","b","ba","bac","bad","ac","d"};

    cout << solution2.countConsistentStrings(allowed, words) << endl;
    cout << solution2.countConsistentStrings(allowed2, words2) << endl;
    cout << solution2.countConsistentStrings(allowed3, words3) << endl;

    return 0;
}