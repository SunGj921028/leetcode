#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> mp;
        vector<int > uniqueNum = arr;
        sort(uniqueNum.begin(), uniqueNum.end());
        // Move the duplicate value to the of the vector and return the start position of the duplicate remaining.
        // Then, erase the elements from the return position to the end fo uniqueNum
        uniqueNum.erase(unique(uniqueNum.begin(), uniqueNum.end()), uniqueNum.end());
        
        for(int i = 0; i < uniqueNum.size(); i++){
            mp[uniqueNum[i]] = i + 1;
        }

        for(int i = 0; i < arr.size(); i++){
            arr[i] = mp[arr[i]];
        }

        return arr;
    }
};

// 5 9 12 12 28 37 56 80 100

int main(){
    Solution* obj = new Solution();
    // vector<int> arr = {40,10,20,30};
    vector<int> arr = {37, 12, 28, 9, 100, 56, 80, 5, 12};
    vector<int> output = obj->arrayRankTransform(arr);
    for(int i : output){
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}