#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string swap_char(string cur, int i, int j){
        char tmp = cur[i];
        cur[i] = cur[j];
        cur[j] = tmp;
        return cur;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        int m = 2, n = 3;
        string target = "123450";
        //! transform the 2*3 board to a string as the start point of the BFS
        string start = "";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                start += to_string(board[i][j]);
            }
        }
        // 记录一维字符串的相邻索引
        // 0 1 2
        // 3 4 5
        vector<vector<int>> neighbor = {
            {1, 3}, //! Neighbors of 0
            {0, 4, 2}, //! Neighbors of 1
            {1, 5}, //! Neighbors of 2
            {0, 4}, //! Neighbors of 3
            {3, 1, 5}, //! Neighbors of 4
            {4, 2} //! Neighbors of 5
        };

        // BFS
        queue<string> q;
        unordered_set<string> visited;
        q.push(start);
        visited.insert(start);
        int step = 0; //! Answer
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                string cur = q.front();
                q.pop();
                if(cur == target){ return step;}
                //! To find the idx of 0
                int idx = 0;
                for(; cur[idx] != '0'; idx++){}
                //! Swap the 0 with its neighbor
                for(int adj : neighbor[idx]){
                    string new_board = swap_char(cur, idx, adj);
                    //! Prevent the same board from being visited again
                    if(!visited.count(new_board)){
                        q.push(new_board);
                        visited.insert(new_board);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> board = {{1, 2, 3}, {4, 0, 5}};
    cout << solution.slidingPuzzle(board) << endl;
    return 0;
}