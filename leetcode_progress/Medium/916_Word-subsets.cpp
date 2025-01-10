#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxCharFreq(26, 0);

        for(const auto& word : words2){
            vector<int> tempCharFreq(26, 0);
            for(char c : word){
                tempCharFreq[c - 'a']++;
            }
            for(int i = 0; i < 26; i++){
                maxCharFreq[i] = max(maxCharFreq[i], tempCharFreq[i]);
            }
        }

        vector<string> ans;
        for(const auto& word : words1){
            vector<int> tempCharFreq(26, 0);
            for(char c : word){
                tempCharFreq[c - 'a']++;
            }
            bool isUniversal = true;
            for(int i = 0; i < 26; i++){
                if(tempCharFreq[i] < maxCharFreq[i]){
                    isUniversal = false;
                    break;
                }
            }
            if(isUniversal){
                ans.emplace_back(word);
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> words1 = {"amazon","apple","facebook","google","leetcode"};
    vector<string> words2 = {"e","o"};
    vector<string> res = s.wordSubsets(words1, words2);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}