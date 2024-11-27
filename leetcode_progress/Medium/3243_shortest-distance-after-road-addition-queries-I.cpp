#include<bits/stdc++.h>

using namespace std;

//! BFS
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        //? Create initial adjacency list
        vector<vector<int> > adj(n);
        for(int i = 0; i < n; i++){
            adj[i].push_back(i + 1);
        }

        //! Lambda function to find shortest path
        auto shortest_path = [&](){
            queue<pair<int, int>> q;
            q.push({0, 0}); // {node, length}
            unordered_set<int> visited;
            visited.insert(0);

            while(!q.empty()){
                auto [cur, length] = q.front();
                q.pop();

                if(cur == n - 1){ return length;}

                for(int nei : adj[cur]){
                    if(visited.find(nei) == visited.end()){
                        visited.insert(nei);
                        q.push({nei, length + 1});
                    }
                }
            }
            return -1;
        };

        vector<int> result;
        for(const auto& query : queries){
            adj[query[0]].push_back(query[1]);
            result.push_back(shortest_path());
        }
        return result;
    }
};

//! DFS
class Solution2 {
    void updateDistances(vector<vector<int>>& graph, int current, vector<int>& distances) {
        int newDist = distances[current] + 1;
        for (int neighbor : graph[current]) {
            if (distances[neighbor] <= newDist) continue;
            distances[neighbor] = newDist;
            updateDistances(graph, neighbor, distances);
        }
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> distances(n);
        for (int i = 0; i < n; ++i) {
            distances[i] = n - 1 - i;
        }
        
        vector<vector<int>> graph(n);
        for (int i = 0; i + 1 < n; ++i) {
            graph[i + 1].push_back(i);
        }
        
        vector<int> answer(queries.size());
        int queryIdx = 0;
        
        for (const auto& query : queries) {
            int source = query[0];
            int target = query[1];
            
            graph[target].push_back(source);
            distances[source] = min(distances[source], distances[target] + 1);
            updateDistances(graph, source, distances);
            
            answer[queryIdx++] = distances[0];
        }
        
        return answer;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> queries = {{2, 4}, {0, 2}, {0, 4}};
    vector<int> result = sol.shortestDistanceAfterQueries(5, queries);
    for(auto res : result){
        cout << res << " ";
    }
    cout << endl;
    return 0;
}