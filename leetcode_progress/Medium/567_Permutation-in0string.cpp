#include<bits/stdc++.h>

using namespace std;

//! Sliding window
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;
        for(auto c : s1){
            mp[c]++;
        }

        int start = 0, end = 0;
        int windowLen = s2.size();
        int requiredLen = s1.size();

        while(end < windowLen){
            // Decrease the frequency if it is exist in s2
            if(mp[s2[end]] > 0){
                requiredLen--; // First decrease the required length
            }
            mp[s2[end]]--;
            end++; // Move the right pointer

            // If the required length is 0, then we found the permutation
            if(requiredLen == 0){ return true;}

            // If the window size is greater than the s1 size
            if(end - start == s1.size()){
                if(mp[s2[start]] >= 0){
                    requiredLen++;
                }
                mp[s2[start]]++;
                start++;
            }
        }
        return false;
    }
};

int main(){
    Solution* obj = new Solution();
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << obj->checkInclusion(s1, s2) << "\n";
    return 0;
}