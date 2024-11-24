#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int sumOfAbsolutesNums = 0;
        int minAbsoluteNum = INT_MAX;
        int countOfNegatives = 0;
        for(auto row : matrix){
            for(auto num : row){
                if(num < 0){ countOfNegatives++;}
                minAbsoluteNum = min(minAbsoluteNum, abs(num));
                sumOfAbsolutesNums += abs(num);
            }
        }
        if(countOfNegatives % 2 == 0){
            return sumOfAbsolutesNums;
        }else{
            return sumOfAbsolutesNums - 2 * minAbsoluteNum; //! Twice means + the negative number of the minAbsoluteNum
        }
    }
};

int main(){
    Solution solution;
    vector<vector<int>> matrix = {{1, 2, 3}, {-1, -2, -3}, {1, 2, 3}};
    cout << solution.maxMatrixSum(matrix) << endl;
    return 0;
}