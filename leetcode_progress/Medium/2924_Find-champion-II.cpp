#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int > inDegree(n, 0);

        for(auto edge : edges){
            inDegree[edge[1]]++;
        }

        vector<int > champions;
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0){
                champions.push_back(i);
            }
        }

        if(champions.size() != 1){
            return -1;
        }
        return champions[0];
    }
};

int main(){
    Solution sol;
    vector<vector<int>> edges = {{0, 1}, {1, 2}};
    cout << sol.findChampion(3, edges) << endl;
    return 0;
}