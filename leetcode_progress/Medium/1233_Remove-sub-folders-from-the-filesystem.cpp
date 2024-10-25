#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(), folder.end());
        ans.push_back(folder[0]);
        for(int i = 1; i < folder.size(); i++){
            if(folder[i].find(ans.back() + "/") == string::npos){
                ans.push_back(folder[i]);
            }else if(folder[i].substr(0, ans.back().size() + 1) != ans.back() + "/"){
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<string> folder = {"/a","/a/b","/c/d","/c/d/e","/c/f"};
    vector<string> result = sol.removeSubfolders(folder);
    for(auto str : result){
        cout << str << " ";
    }
    cout << endl;
    return 0;
}