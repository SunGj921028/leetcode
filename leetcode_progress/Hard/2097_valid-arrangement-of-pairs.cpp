#include<bits/stdc++.h>

using namespace std;

//! find an Eulerian path of this graph. Hierholzer’s algorithm can be used.
class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> deg; //? net outdegree
    inline void build_graph(vector<vector<int> >& pairs){
        for(auto& edge : pairs){
            int start = edge[0], end = edge[1];
            adj[start].push_back(end);
            deg[start]++;
            deg[end]--;
        }
    }

    vector<int> rpath;
    inline void euler(int i){
        while(!adj[i].empty()){
            int j = adj[i].back();
            adj[i].pop_back();
            euler(j);
        }
        rpath.push_back(i);
    }


    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        const int e = pairs.size();
        adj.reserve(e);
        deg.reserve(e);

        build_graph(pairs);

        int i0 = deg.begin()->first;
        //! Find start vertex for Euler path
        // Find start vertex for Euler path
        for (auto it = deg.begin(); it != deg.end(); ++it) {
            if (it->second == 1) {
                i0 = it->first;
                break;
            }
        }

        euler(i0);
        vector<vector<int>> result;
        result.reserve(e);

        for(int i = rpath.size() - 2; i >= 0; i--){
            result.push_back({rpath[i + 1], rpath[i]});
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<vector<int>> pairs = {{5, 1}, {4, 5}, {11, 9}, {9, 4}};
    vector<vector<int>> result = s.validArrangement(pairs);
    for (auto& v : result) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}