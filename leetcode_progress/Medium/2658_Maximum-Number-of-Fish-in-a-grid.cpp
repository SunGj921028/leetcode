#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j){
        int rows = grid.size(), cols = grid[0].size();
        if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == 0) return 0;

        int currfish = grid[i][j];
        grid[i][j] = 0;

        int up = dfs(grid, i - 1, j);
        int down = dfs(grid, i + 1, j);
        int left = dfs(grid, i, j - 1);
        int right = dfs(grid, i, j + 1);

        currfish += (up + down + left + right);
        return currfish;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int maxFish = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0 ; j < grid[0].size(); j++){
                if(grid[i][j] != 0){
                    maxFish = max(maxFish, dfs(grid, i, j));
                }
            }
        }
        return maxFish;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {{0, 2, 1, 0}, {4, 0, 0, 3}, {1, 0, 0, 4}, {0, 3, 2, 0}};
    cout << sol.findMaxFish(grid) << endl;
    return 0;
}