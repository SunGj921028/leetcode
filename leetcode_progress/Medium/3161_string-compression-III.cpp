#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int count = 0; //! At most 9
        for(int i = 0; i < word.size(); i++){
            count++;
            if(i == word.size() - 1 || word[i] != word[i + 1] || count == 9){
                comp += to_string(count) + word[i];
                count = 0;
            }
        }
        return comp;
    }
};

int main(){
    Solution solution;
    string word = "abcde";
    //! Output: "1a1b1c1d1e"
    cout << solution.compressedString(word) << endl;
    return 0;
}