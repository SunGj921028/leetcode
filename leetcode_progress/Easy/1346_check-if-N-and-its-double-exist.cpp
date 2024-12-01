#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> hashset;
        for(int i = 0; i < arr.size(); i++){
            if((hashset.find(arr[i] * 2) != hashset.end()) || (arr[i] % 2 == 0 && hashset.find(arr[i] / 2) != hashset.end())){
                return true;
            }else{ hashset.insert(arr[i]);}
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<int> arr = {10, 2, 5, 3};
    cout << s.checkIfExist(arr) << endl;
    return 0;
}