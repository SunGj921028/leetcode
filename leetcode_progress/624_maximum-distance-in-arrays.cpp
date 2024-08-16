#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int smallest = arrays[0][0];
        int biggest = arrays[0].back();
        int max_distance = 0;

        for (int i = 1; i < arrays.size(); ++i) {
            max_distance = max(max_distance, abs(arrays[i].back() - smallest));
            max_distance = max(max_distance, abs(biggest - arrays[i][0]));
            smallest = min(smallest, arrays[i][0]);
            biggest = max(biggest, arrays[i].back());
        }

        return max_distance;
    }
};

int main() {
    Solution s;
    vector<vector<int>> arrays = {{1,2,3},{4,5},{1,2,3}};
    vector<vector<int>> arrays2 = {{1},{1}};
    vector<vector<int>> wrongcase = {{1,4},{0,5}};
    vector<vector<int>> wrongcase2 = {{1,5},{3,4}};
    vector<vector<int>> wrongcase3 = {{-3,-3},{-3,-2}};
    vector<vector<int>> wrongcase4 = {{-10,-9,-9,-3,-1,-1,0},{-5},{4},{-8},{-9,-6,-5,-4,-2,2,3},{-3,-3,-2,-1,0}};
    cout << s.maxDistance(wrongcase4) << endl;
}