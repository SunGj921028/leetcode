#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int numMagicSquaresInside(vector<vector<int>>& grid) {
            int res = 0;
            unordered_map<int, int> mp; // To check if the number in grid is from 1 to 9
            int row = grid.size(), col = grid[0].size();
            int check = 1;
            if(row < 3 || col < 3){ return 0;}

            // Iterate the whole grid
            for(auto i = 0; i < row; i++){
                for(auto j = 0; j < col; j++){
                    // Check if the current cell is on the edge of the grid
                    if((i - 1 >= 0) && (j - 1 >= 0) && (j + 1 < col) && (i + 1 < row)){
                        for(auto mRow = i - 1; mRow <= i + 1 && check ; mRow++){
                            for(auto mCol = j - 1; mCol <= j + 1 && check ; mCol++){
                                if(grid[mRow][mCol] < 1 || grid[mRow][mCol] > 9){ check = 0; continue;}
                                if(mp[grid[mRow][mCol]] == 0){
                                    mp[grid[mRow][mCol]] = 1;
                                }else{
                                    check = 0;
                                }
                            }
                        }
                        mp.clear();
                        if(!check){ check = 1; continue;}
                        int sum = grid[i][j] + grid[i][j - 1] + grid[i][j + 1];
                        if(grid[i - 1][j] + grid[i - 1][j - 1] + grid[i - 1][j + 1] != sum){ continue;}
                        if(grid[i + 1][j] + grid[i + 1][j - 1] + grid[i + 1][j + 1] != sum){ continue;}
                        if(grid[i][j] + grid[i - 1][j] + grid[i + 1][j] != sum){ continue;}
                        if(grid[i][j] + grid[i - 1][j] + grid[i + 1][j] != sum){ continue;}
                        if(grid[i][j + 1] + grid[i - 1][j + 1] + grid[i + 1][j + 1] != sum){ continue;}
                        if(grid[i][j - 1] + grid[i - 1][j - 1] + grid[i + 1][j - 1] != sum){ continue;}
                        if(grid[i][j] + grid[i - 1][j - 1] + grid[i + 1][j + 1] != sum){ continue;}
                        if(grid[i][j] + grid[i + 1][j - 1] + grid[i - 1][j + 1] != sum){ continue;}
                        res++;
                    }
                }
            }
            return res;
        }
};

class Solution2 {
    public: 
        bool isMagic(int i, int j, vector<vector<int>>& grid){
            int col1=grid[i][j]+grid[i][j+1]+grid[i][j+2];
            int col2=grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2];
            int col3=grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
            int row1=grid[i][j]+grid[i+1][j]+grid[i+2][j];
            int row2=grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1];
            int row3=grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2];
            int dia1=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
            int dia2=grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];

            if((col1==col2) && (col1==col3) && (col1==row1) && (col1==row2) && (col1==row3) && (col1==dia1) && (col1==dia2)){
                set<int>s{1,2,3,4,5,6,7,8,9}; // To check whether the numbers in grid is range from 1 to 9
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        s.erase(grid[i+k][j+l]);
                    }
                }
                return s.empty();
            }
            return false;
        }
        int numMagicSquaresInside(vector<vector<int>>& grid) {
            int cnt = 0;
            int row = grid.size();
            int col = grid[0].size();
            
            if(row < 3 || col < 3) return 0;

            for(int i = 0; i <= row - 3; ++i) { // start from the left-top corner
                for(int j = 0; j <= col - 3; ++j) {
                    if(isMagic(i, j, grid)) cnt++;
                }
            }
            return cnt;
        }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{8}};
    cout << s.numMagicSquaresInside(grid) << endl;
    return 0;
}