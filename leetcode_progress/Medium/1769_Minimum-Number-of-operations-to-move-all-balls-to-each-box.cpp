#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size(), 0);
        for(int i = 0; i < boxes.size(); i++){
            for(int j = 0; j < boxes.size(); j++){
                if(i != j && boxes[j] == '1'){
                    ans[i] += abs(i - j);
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    string boxes = "110";
    vector<int> res = s.minOperations(boxes);
    for(auto & r : res){
        cout << r << " ";
    }
    cout << endl;
    return 0;
}