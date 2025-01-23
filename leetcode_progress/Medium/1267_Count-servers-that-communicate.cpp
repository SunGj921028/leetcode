#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> rowCount(row);
        vector<int> colCount(col);

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                rowCount[i] += grid[i][j];
                colCount[j] += grid[i][j];
            }
        }

        int ans = 0;
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if(grid[r][c] == 1 && (rowCount[r] > 1 || colCount[c] > 1)){
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    int ans = s.countServers(grid);
    cout << ans << "\n";
    return 0;
}