#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int> > grid(m, vector<int>(n, 0));
        //! mark guards and walls as 2
        for (auto guard : guards) {
            grid[guard[0]][guard[1]] = 2;
        }
        for (auto wall : walls) {
            grid[wall[0]][wall[1]] = 2;
        }
        //! Directions: up, right, down, left
        int dirs[5] = {-1, 0, 1, 0, -1};
        
        //! Process each guard's line of sight
        for(auto guard : guards){
            for(int i = 0; i < 4; ++i){
                int x = guard[0];
                int y = guard[1];
                int dx = dirs[i];
                int dy = dirs[i + 1];

                // Check cells in current direction until hitting boundary or obstacle
                while (x + dx >= 0 && x + dx < m && y + dy >= 0 && y + dy < n && grid[x + dx][y + dy] < 2) {
                    x += dx;
                    y += dy;
                    grid[x][y] = 1;
                }
            }
        }

        int unguardedCount = 0;
        for (int i = 0; i < m; i++) {
            unguardedCount += std::count(grid[i].begin(), grid[i].end(), 0);
        }
        return unguardedCount;
    }
};

int main(){
    Solution solution;
    int m = 4;
    int n = 6;
    vector<vector<int>> guards = {{0, 0}, {1, 1}, {2, 3}};
    vector<vector<int>> walls = {{0, 1}, {2, 2}, {1, 4}};
    cout << solution.countUnguarded(m, n, guards, walls) << endl;
    return 0;
}