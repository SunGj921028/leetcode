#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        int n = v.size();
        for(int i = n-1; i >= 0; i--){
            if(i == n-1)
                v[i]++;
            if(v[i] == 10){
                v[i] = 0;
                if(i != 0){
                    v[i-1]++;
                }
                else{
                    v.push_back(0);
                    v[i] = 1;
                }
            }
        }
        return v;
    }
};

int main(){
    Solution solution;
    vector<int> v = {9,9,9};
    vector<int> ret = solution.plusOne(v);
    for(int i = 0; i < ret.size(); i++){
        cout << ret[i] << " ";
    }
    cout << endl;
    return 0;
}