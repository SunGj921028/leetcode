#include<bits/stdc++.h>

using namespace std;

class Solution {
    public: 
        string kthDistinct(vector<string>& arr, int k){
            unordered_map<string, int> mp;
            for(auto s : arr){
                mp[s]++;
            }
            int cnt = 0;
            for(auto s : arr){
                if(mp[s] == 1){ cnt++;}
                if(cnt == k){ return s;}
            }
            return "";
        }
};

int main(){
    Solution s;
    vector<string> arr = {"d", "b", "c", "b", "c", "a"};
    vector<string> arr2 = {"aaa", "aa", "a"};
    int k = 1;
    cout << s.kthDistinct(arr2, k) << endl;
}