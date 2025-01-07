#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words.size(); j++){
                if(i != j && words[j].find(words[i]) != string::npos){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> words = {"mass","as","hero","superhero"};
    vector<string> res = s.stringMatching(words);
    for(auto & r : res){
        cout << r << " ";
    }
    cout << endl;
    return 0;
}