#include<bits/stdc++.h>

using namespace std;

//! Medium
//? https://leetcode.com/problems/largest-number/description/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        // convert int to string
        vector<string > arr;
        for(int num : nums){
            arr.push_back(to_string(num));
        }

        //! Custom comparator for sorting
        sort(arr.begin(), arr.end(), [](const string &a, const string &b) {
            return (b + a) < (a + b);
        });

        // if the first element is 0, then return 0
        if(arr[0] == "0") return "0";

        // Build the answer string
        for(string s : arr){
            ans += s;
        }

        return ans;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {10,2};
    vector<int> nums2 = {3,30,34,5,9};
    cout << solution.largestNumber(nums) << endl;
    cout << solution.largestNumber(nums2) << endl;
    return 0;
}