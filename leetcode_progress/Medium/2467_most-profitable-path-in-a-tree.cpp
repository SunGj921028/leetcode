#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n;
    vector<int> distanceFromBob;
    vector<vector<int> > tree;

    int findPaths(int sourceNode, int parentNode, int time, int bob, vector<int>& amount){
        int maxIncome = 0, maxChild = INT_MIN;

        // Find the node distance from Bob
        if(sourceNode == bob){
            distanceFromBob[sourceNode] = 0;
        }else{
            distanceFromBob[sourceNode] = n;
        }

        for(auto adjacentNode : tree[sourceNode]){
            if(adjacentNode != parentNode){
                maxChild = max(maxChild, findPaths(adjacentNode, sourceNode, time + 1, bob, amount));
                distanceFromBob[sourceNode] = min(distanceFromBob[sourceNode], distanceFromBob[adjacentNode] + 1);
            }
        }

        //! Alice reaches the node first
        if(distanceFromBob[sourceNode] > time){ maxIncome += amount[sourceNode]; }
        else if(distanceFromBob[sourceNode] == time){ maxIncome += amount[sourceNode] / 2; }

        if (maxChild == INT_MIN){ return maxIncome; }
        else{ return maxIncome + maxChild; }
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        n = amount.size(); // Number of nodes
        tree.resize(n, vector<int>()); //! Adjacency list representation of the tree

        //? Form tree with edges
        for(auto edge: edges){
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]); //! undirected graph
        }
        distanceFromBob.resize(n, 0);
        return findPaths(0, 0, 0, bob, amount);
    }
};

int main(){
    Solution sol;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}, {3, 4}};
    int bob = 0;
    vector<int> amount = {-2, 4, 2, -4, 6};
    cout << sol.mostProfitablePath(edges, bob, amount) << endl;
    return 0;
}