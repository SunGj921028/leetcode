#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1 == sentence2){ return true;}
        vector<string> s1, s2;
        // Because the words are separated by single white space
        //TODO Split sentences into words:
        stringstream ss1(sentence1);
        stringstream ss2(sentence2);
        string word;
        while(ss1 >> word){
            s1.push_back(word);
        }
        while(ss2 >> word){
            s2.push_back(word);
        }
        if(s1.size() < s2.size()){
            swap(s1, s2);
        }
        int n1 = s1.size(), n2 = s2.size();
        
        int start = 0, end = 0;
        // Compare from the start (prefix)
        while (start < n2 && s1[start] == s2[start]) start++;
        
        // Compare from the end (suffix)
        while (end < n2 && s1[n1 - end - 1] == s2[n2 - end - 1]) end++;
        
        // Check if the remaining unmatched part is in the middle
        return (start + end >= n2);
    }
};

int main(){
    Solution* obj = new Solution();
    string sentence1 = "of";
    string sentence2 = "A lot of words";
    cout << obj->areSentencesSimilar(sentence1, sentence2) << "\n";
    return 0;
}