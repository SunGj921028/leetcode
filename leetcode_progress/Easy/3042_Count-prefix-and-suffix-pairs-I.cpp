#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool isPrefixAndSuffix(string s1, string s2){
        if(s1.size() > s2.size()){ return false;}
        return s2.find(s1) == 0 && s2.rfind(s1) == s2.size() - s1.size();
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for(int i = 0; i < words.size(); i++){
            for(int j = i + 1; j < words.size(); j++){
                if(isPrefixAndSuffix(words[i], words[j])){ count++;}
            }
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<string> words = {"a","aba","ababa","aa"};
    cout << s.countPrefixSuffixPairs(words) << endl;
    return 0;
}