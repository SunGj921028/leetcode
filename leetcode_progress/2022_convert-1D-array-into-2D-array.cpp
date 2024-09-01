#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> res(m, vector<int>(n));
        if(m * n != original.size()){ return {}; }
        int idx = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                res[i][j] = original[idx++];
            }
        }

        return res;
    }
};

int main(){
    Solution s;
    vector<int> original = {1,2,3,4};
    int m = 2;
    int n = 2;
    vector<vector<int>> res = s.construct2DArray(original, m, n);
    for (auto row : res) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}