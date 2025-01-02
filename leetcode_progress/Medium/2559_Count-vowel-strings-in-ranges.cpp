#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), 0);
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        // Precompute the prefix sum of strings that starts and end with vowels
        vector<int> prefix(words.size(), 0);
        for(int i = 0; i < words.size(); i++){
            prefix[i] = ( i > 0 ? prefix[i - 1] : 0);
            if(vowels.find(words[i][0]) != vowels.end() && vowels.find(words[i][words[i].size() - 1]) != vowels.end()){
                prefix[i]++;
            }
        }

        for(int i = 0; i < queries.size(); i++){
            int l = queries[i][0], r = queries[i][1];
            ans[i] = prefix[r] - (l > 0 ? prefix[l - 1] : 0);
        }

        return ans;
    }
};

int main(){
    Solution s;
    vector<string> words = {"aba", "bcb", "ece", "aa", "e"};
    vector<vector<int>> queries = {{0, 2}, {1, 4}, {1, 1}};
    vector<int> res = s.vowelStrings(words, queries);
    for(int i=0; i<res.size(); i++){
        cout << res[i] << " ";
    }
    cout<<endl;
    return 0;
}