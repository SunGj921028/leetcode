#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        vector<vector<int>> res = {{0, 0}};

        for(const auto& item : items){
            int price = item[0];
            int beauty = item[1];
            if(beauty > res.back()[1]){
                res.push_back({price, beauty});
            }
        }

        cout << queries.size() << endl;
        vector<int> ans(queries.size());
        for(int x = 0 ; x < queries.size(); x++){
            for(int i = res.size() - 1; i >= 0; i--){
                if(res[i][0] <= queries[x]){
                    ans[x] = res[i][1];
                    break;
                }
            }
        }
        return ans;
        
    }
};

int main(){
    Solution solution;
    vector<vector<int>> items = {{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}};
    vector<int> queries = {1, 2, 3, 4, 5, 6};
    vector<int> result = solution.maximumBeauty(items, queries);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}