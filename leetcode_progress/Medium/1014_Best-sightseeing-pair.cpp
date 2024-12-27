#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = 0;
        int maxLeft = values[0];
        for(int i = 1; i < values.size(); i++){
            maxScore = max(maxScore, maxLeft + values[i] - i);
            maxLeft = max(maxLeft, values[i] + i);
        }
        return maxScore;
    }
};

int main(){
    Solution solution;

    vector<int> values = {8, 1, 5, 2, 6};
    int result = solution.maxScoreSightseeingPair(values);
    cout << result << endl;

    return 0;
}