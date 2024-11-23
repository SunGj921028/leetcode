#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rowNum = box.size();
        int colNum = box[0].size();
        vector<vector<char>> result(colNum, vector<char>(rowNum, '.'));
        for(int i = 0 ; i < rowNum; i++){
            int k = colNum - 1;
            for(int j = colNum - 1 ;j >= 0; j--){
                if(box[i][j] == '#'){
                    result[k][rowNum - i - 1] = '#';
                    k--; //! Next position for the stone（UP the current one）
                }else if(box[i][j] == '*'){
                    result[j][rowNum - i - 1] = '*';
                    k = j - 1; //! when hit some opstacle > reset position
                }
            }
        }
        return result;
    }
};

int main(){
    Solution solution;
    vector<vector<char>> box = {{'#', '.', '#'}};
    vector<vector<char>> box2 = {{'#', '.', '*', '.'}, {'#', '#', '*', '.'}};
    vector<vector<char>> reesult1 = solution.rotateTheBox(box);
    vector<vector<char>> reesult2 = solution.rotateTheBox(box2);
    for (const auto& row : reesult1) {
        for (const auto& ch : row) {
            cout << ch << ' ';
        }
        cout << endl;
    }
    cout << endl;
    for (const auto& row : reesult2) {
        for (const auto& ch : row) {
            cout << ch << ' ';
        }
        cout << endl;
    }
    return 0;
}