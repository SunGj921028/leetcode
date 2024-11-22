#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> patFreq;

        for(const auto& row : matrix){
            string pattern;
            if(row[0] == 0){
                for(int bit : row){
                    pattern += to_string(bit);
                }
            }else{
                for(int bit : row){
                    pattern += to_string(bit ^ 1);
                }
            }
            patFreq[pattern]++;
        }

        int maxFreq = 0;
        for(const auto& pair : patFreq){
            maxFreq = max(maxFreq, pair.second);
        }
        return maxFreq;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> matrix = {{0, 1}, {1, 1}};
    vector<vector<int>> matrix2 = {{0, 0, 0}, {0, 0, 1}, {1, 1, 0}};
    cout << solution.maxEqualRowsAfterFlips(matrix) << endl;
    return 0;
}