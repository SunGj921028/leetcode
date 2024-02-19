#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
    public: 
        vector<vector<string > > groupAnagrams(vector<string> &strs){
            unordered_map<string, vector<string> > mp;
            for(string s : strs){
                string t = s;
                sort(t.begin(), t.end());
                mp[t].push_back(s);
            }
            vector<vector<string> > anagrams;
            for(auto p : mp){
                anagrams.push_back(p.second);
            }
            return anagrams;
        }
};

class Solution2 {
    public: 
        vector<vector<string > > groupAnagrams(vector<string> &strs){
            unordered_map<string, vector<string> > mp;
            for(string s : strs){
                // encode the string
                vector<int> count(26, 0);
                for(char c : s){
                    count[c - 'a']++;
                }
                string key(count.begin(), count.end());
                // 把编码相同的字符串放在一起
                mp[key].push_back(s);
            }
            vector<vector<string> > anagrams;
            for(auto p : mp){
                anagrams.push_back(p.second);
            }
            return anagrams;
        }
};