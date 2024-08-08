#include<bits/stdc++.h>

using namespace std;

class Solution {
    public: 
        vector<vector<int >> spiralMatrixIII(int rows, int cols, int rStart, int cStart){
            vector<vector<int >> res;
            int rowDir = 0;
            int colDir = 1;
            int r = rStart, c = cStart;
            int switchTwice = 2;
            int moveStep = 1;
            int nextMoveStep = 2;

            while(res.size() < (rows * cols)){
                if(r < rows && c < cols && r >= 0 && c >= 0){
                    res.push_back({r,c});
                }

                r += rowDir;
                c += colDir;
                moveStep--;
                // End of moving in this direction
                if(moveStep == 0){
                    // Switch direction of row and col
                    int temp = rowDir;
                    rowDir = colDir;
                    colDir = temp;
                    switchTwice--;
                    if(switchTwice == 0){
                        switchTwice = 2;
                        // Adjust the sign of colDir when switch direction twice
                        colDir *= -1;
                        // Length of step plus 1
                        moveStep = nextMoveStep;
                        nextMoveStep++;
                    }else{
                        // Still have length to go
                        moveStep = nextMoveStep - 1;
                    }
                }
            }
            return res;
        }
};

int main(){
    Solution s;
    vector<vector<int> > res = s.spiralMatrixIII(5, 6, 1, 4);
    for(auto x: res){
        cout << x[0] << " " << x[1] << endl;
    }
    return 0;
}