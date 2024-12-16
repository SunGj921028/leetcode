#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2, 1, 3, 5, 6};
    int k = 5;
    int multiplier = 2;
    vector<int> res = sol.getFinalState(nums, k, multiplier);
    for(int i=0; i<res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}