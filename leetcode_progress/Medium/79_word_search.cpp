#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
    public:
        bool exist(vector<vector<char > >& board, string word){
            if(board.size() <= 0 || word.size() <= 0){ return false;}
            int row = board.size();
            // int col = board.back().size();
            int col = board[0].size();

            for(int i = 0;i < row; i++){
                for(int j = 0;j < col; j++){
                    if(board[i][j] == word[0]){
                        if(dfs(board, word, i, j, 0)){
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        bool dfs(vector<vector<char > >& board, string& word, int row, int col, int idx_word){
            if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[idx_word]){ return false;}
            if(idx_word + 1 == word.size()){ return true;}
            
            board[row][col] = '\0';

            // four directions
            if( dfs(board, word, row + 1, col, idx_word + 1) || dfs(board, word, row - 1, col, idx_word + 1) || 
                dfs(board, word, row, col + 1, idx_word + 1) || dfs(board, word, row, col - 1, idx_word + 1) ){
                return true;
            }

            board[row][col] = word[idx_word];
            return false;
        }
};

int main(){
    Solution sol;
    vector<vector<char > > board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCB";
    cout << sol.exist(board, word) << endl;
    return 0;
}