#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    unordered_set<string> numSet;
    string generate(string curr){
        if(curr.size() == n){
            if(numSet.find(curr) == numSet.end()){
                return curr;
            }
            return "";
        }

        string addZero = generate(curr + "0");
        if(addZero.size() != 0){ return addZero; }
        return generate(curr + "1");
    }

    string findDifferentBinaryString(vector<string>& nums) {
        n = nums.size();
        for(string s : nums){
            numSet.insert(s);
        }
        return generate(""); //! start from empty string
    }
};

class Solution2 {
public:
    string findDifferentBinaryString(vector<string>& nums){
        string ans = "";
        for(int i = 0; i < nums.size(); i++){
            ans += (nums[i][i] == '0') ? '1' : '0';
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> nums = {"01", "10"};
    cout << s.findDifferentBinaryString(nums) << endl;
    return 0;
}