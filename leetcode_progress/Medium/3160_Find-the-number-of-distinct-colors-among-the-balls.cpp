#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        unordered_map<int, int> colorMp, ballMp;
        vector<int> ans;
        for(auto &entry : queries){
            int ball = entry[0], color = entry[1];

            if(ballMp.find(ball) != ballMp.end()){ //! Ball exist
                int oldColor = ballMp[ball];
                colorMp[oldColor]--;
                if(colorMp[oldColor] == 0){
                    colorMp.erase(oldColor);
                }
            }

            ballMp[ball] = color;
            colorMp[color]++;
            ans.push_back(colorMp.size());
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> queries = {{1, 4}, {2, 5}, {1, 3}, {3, 4}};
    vector<int> results = s.queryResults(4, queries);
    for(int result : results){
        cout << result << " ";
    }
    cout << "\n";
    return 0;
}