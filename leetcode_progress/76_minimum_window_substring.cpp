#include<iostream>
#include<string>
#include<bits/stdc++.h>
// #include<vector>

using namespace std;

class Solution {
    public: 
        string minWindow(string s, string t){
            if(s.empty() || t.empty() || s.length() < t.length()){ return "";}

            vector<int > map(128, 0);
            int count = t.length();
            int start = 0, end = 0, minLen = INT_MAX, startIdx = 0;
            // update the character frequency in the map
            for(auto c : t){
                map[c]++;
            }
            while(end < s.length()){
                if(map[s[end]]-- > 0){
                    count--;
                }
                end++;

                // when count is 0, we have found the current window which has all the characters of t
                while(!count){
                    // Update the minimum length and start index
                    if(end - start < minLen){
                        minLen = end - start;
                        startIdx = start;
                    }
                    // Increase the start pointer to find the next window
                    if(map[s[start++]]++ == 0){
                        count++;
                    }
                }
                // cout << start << " " << end << endl;
            }
            return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
        }
};