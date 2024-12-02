#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int count = 1;
        for(auto c : sentence){
            if(c == ' '){ count++; }
        }
        istringstream iss(sentence);
        string word;
        for(int i = 1; i <= count; i++){
            iss >> word;
            if(word.find(searchWord) == 0){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    string sentence = "i love eating burger";
    string searchWord = "burg";
    cout << s.isPrefixOfWord(sentence, searchWord) << endl;
    return 0;
}