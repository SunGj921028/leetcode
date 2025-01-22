#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rows = mat.size(), col = mat[0].size();
        unordered_map<int, pair<int, int> > positionMap;
        vector<int> rowCount(rows, col), colCount(col, rows);

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < col; c++){
                positionMap[mat[r][c]] = {r, c};
            }
        }

        for(int idx = 0; idx < arr.size(); idx++){
            int val = arr[idx];
            auto [r, c] = positionMap[val];
            if(--rowCount[r] == 0 || --colCount[c] == 0){
                return idx;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> arr = {1, 3, 4, 2};
    vector<vector<int>> mat = {{1, 4}, {2, 3}};
    cout << s.firstCompleteIndex(arr, mat) << endl;
    return 0;
}