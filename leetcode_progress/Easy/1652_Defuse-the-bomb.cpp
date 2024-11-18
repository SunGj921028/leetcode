#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if(!k){ return vector<int> (code.size(), 0); }
        int n = code.size();
        vector<int> result(n);
        for(int i = 0; i < n; i++){
            int sum = 0;
            if(k > 0){
                for(int j = 1; j <= k; j++){
                    sum += code[(i + j) % n];
                }
            } else {
                for(int j = 1; j <= abs(k); j++){
                    sum += code[(i - j + n) % n];
                }
            }
            result[i] = sum;
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> code = {5, 7, 1, 4};
    int k = 3;
    vector<int> result = s.decrypt(code, k);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}